#!/usr/bin/env python3
import os
import sys
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
    projectName = ""
    projectPath = ""
    if projectOption == "--path":
        projectName = os.getcwd()
    else:
        projectName = input("Project Name \x1b[90m[aloo-project]: ") or "aloo-project"
        os.system(f"mkdir {projectName}")
        projectPath = projectName + "/"
    appName = input("App Description \x1b[90m[Example App]: ") or "Example App"
    appDesc = (
        input("App Description \x1b[90m[An default template app for aloo project]: ")
        or "An default template app for aloo project"
    )

    currFilePath = "/".join(__file__.split("/")[:-1])
    if currFilePath.endswith("bin"):
        currFilePath = "/".join(__file__.split("/")[:-3]) + "/etc/aloo/"

    if "aloo.config.yaml" in os.listdir(os.getcwd()):
        os.system("clear")
        raise FileExistsError("'aloo.config.yaml' already exist")
    appInfo = yaml.dump(
        {"app-name": appName, "description": appDesc, "project-name": projectName},
        open(projectPath + "aloo.config.yaml", "w"),
    )

    os.mkdir(projectPath + "src")
    os.mkdir(projectPath + "test")
    os.system("clear")

    mainC = open(projectPath + "src/main.c", "w+")
    testC = open(projectPath + "test/main.c", "w+")
    CMakeFile = open(projectPath + "CMakeLists.txt", "w+")

    mainCSample = open(
        currFilePath + "main.c",
        "r",
    ).read()

    testCSample = open(
        currFilePath + "test.c",
        "r",
    ).read()

    CMakeSample = open(
        currFilePath + "CMakeLists.txt",
        "r",
    ).read()
    alooDir = currFilePath.removesuffix("scripts/src/")

    mainCSample = mainCSample.replace("$projectName", projectName).replace(
        "$appName", appName
    )
    mainC.write(mainCSample)

    testCSample = testCSample.replace("$projectName", projectName).replace(
        "$appName", appName
    )
    testC.write(testCSample)

    CMakeSample = CMakeSample.replace("$appName", appName).replace(
        "$include_dir", alooDir + "include"
    )
    CMakeSample = CMakeSample.replace("$libaloo", alooDir + "lib").replace(
        "$libaloo", alooDir + "lib"
    )
    CMakeFile.write(CMakeSample)

    colorsCSS = open(
        currFilePath + "styles/colors.css",
        "r",
    ).read()
    materialCSS = open(
        currFilePath + "styles/material.css",
        "r",
    ).read()

    while colorsCSS.index("\t") != -1:
        colorsCSS = colorsCSS.replace("\t", "")
    while colorsCSS.index("\n") != -1:
        colorsCSS = colorsCSS.replace("\n", "")

    while materialCSS.index("\t") != -1:
        materialCSS = materialCSS.replace("\t", "")
    while materialCSS.index("\n") != -1:
        materialCSS = materialCSS.replace("\n", "")

    os.mkdir(projectPath + "styles")
    cssBundle = open(
        projectPath + "styles/material.bundle.min.css",
        "w+",
    )
    cssBundle.write(materialCSS + colorsCSS)

    print("\t\033[1;32m󰄭 Aloo project created successfully\033[0m")


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
                print("Please give with one of the options: [--name | --path]")
                exit(1)
            elif sys.argv[2] != "--name" and sys.argv[2] != "--path":
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
