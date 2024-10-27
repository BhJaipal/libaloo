#!/usr/bin/env python3
import os
import sys
from typing import Union, Optional, Callable
import yaml
import threading
import time
import subprocess
import blessed


def alooHelp() -> None:
    global term
    print("aloocli <command>")
    print()
    print(
        "Aloo CLI is a Command Line Interface for Aloo Library to create a template project and build and run app"
    )
    print()
    print("options:")
    print("  -h, --help               show this help message and exit")
    print("  create-app               creates new template project")
    print("  build                    build aloo project")
    print("  run [app | test ]        runs aloo project [app | tests]")


def createApp(projectOption: str) -> None:
    pass


def loader(i: int):
    match i:
        case 1:
            return "⠛"
        case 2:
            return "⠏"
        case 3:
            return "⡇"
        case 4:
            return "⣆"
        case 5:
            return "⣤"
        case 6:
            return "⣰"
        case 7:
            return "⢸"
        case 8:
            return "⠹"


def buildThread() -> None:
    global buildStarted
    buildStarted = True
    subprocess.run(
        "cmake -S . -B build && cd build && make",
        shell=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    buildStarted = False


def loadingThread() -> None:
    global buildStarted
    i = 8
    while buildStarted:
        term.fullscreen()
        print("\r" + term.yellow(loader(i) + " Building"), end="")
        if i == 1:
            i = 8
        else:
            i -= 1
        time.sleep(0.25)
    else:
        print("\r" + term.green("󰄭 Build done"))


def build() -> None:
    t1 = threading.Thread(target=buildThread, name="t1")
    t2 = threading.Thread(target=loadingThread, name="t2")
    t1.start()
    t2.start()
    t1.join()
    t2.join()


def run(runWhat_App_Test: str) -> None:
    print(term.yellow(f"Running {runWhat_App_Test}"))
    os.system(f"./bin/{runWhat_App_Test}.exe")
    print(term.green("\nApp exited"))


term = blessed.Terminal()
buildStarted = False
if sys.argv.__len__() == 1:
    alooHelp()
else:
    match sys.argv[1]:
        case "-h":
            alooHelp()
        case "--help":
            alooHelp()
        case "create-app":
            if sys.argv.__len__() == 2:
                print("Please give with one of the options: [app | test]")
                exit(1)
            elif sys.argv[2] != "app" and sys.argv[2] != "test":
                print("Option must be either --name or --path")
                exit(1)
            else:
                createApp(sys.argv[2])
        case "build":
            build()
        case "run":
            if sys.argv.__len__() == 2:
                print("Please give with one of the options: [app | test]")
                exit(1)
            elif sys.argv[2] != "app" and sys.argv[2] != "test":
                print("Option must be either app or test")
                exit(1)
            else:
                run(sys.argv[2])
        case _:
            print("Invalid command", sys.argv[1])
