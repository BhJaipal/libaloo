import blessed
import os
from typing import Union, Optional, Callable
import yaml


def emptyLine(end="\n"):
    for _ in range(term.width):
        print(term.royalblue_on_lightblue(" "), end="")
    print(end=end)


def lineSpace(n: float = 1 / 4, isEnd=False) -> str:
    lineSpaces = ""
    global commands
    for i in range(int(n * (term.height - 5))):
        lineSpaces += " "
        for _ in range(term.width - 1):
            lineSpaces += " "
        lineSpaces += "\n"
    lineSpaces = lineSpaces[:-1]
    return lineSpaces


def takeInput() -> None:
    try:
        global commands
        global activeSelection
        global isCommandEnabled
        global exitCommand
        global selectedCommand
        os.system("clear")
        term.fullscreen()
        print(term.royalblue_on_lightblue(lineSpace(1 / 6)))
        print(term.cornflowerblue_on_lightblue((logo[1:-1])))
        print(term.royalblue_on_lightblue(lineSpace(1 / 5, True)))
        for option in commands:
            if commands.index(option) == 0:
                print(
                    term.bold_royalblue_on_lightblue(
                        " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                    )
                    + (
                        term.bold_white_on_cornflowerblue
                        if commands.index(option) == activeSelection[0]
                        else term.bold_royalblue_on_lightblue
                    )(" ┌─────────────────────┐ ")
                    + term.bold_royalblue_on_lightblue(
                        " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                    )
                )
            print(
                term.bold_royalblue_on_lightblue(
                    " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                )
                + (
                    term.bold_bright_white_on_cornflowerblue
                    if commands.index(option) == activeSelection[0]
                    else term.bold_royalblue_on_lightblue
                )((" │ " + option + " " * (20 - len(option)) + "│ "))
                + term.bold_royalblue_on_lightblue(
                    " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                )
            )
            if commands.index(option) == commands.__len__() - 1:
                print(
                    term.bold_royalblue_on_lightblue(
                        " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                    )
                    + (
                        term.bold_bright_white_on_cornflowerblue
                        if commands.index(option) == activeSelection[0]
                        else term.bold_royalblue_on_lightblue
                    )(" └─────────────────────┘ ")
                    + term.bold_royalblue_on_lightblue(
                        " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                    )
                )
            else:
                print(
                    term.bold_royalblue_on_lightblue(
                        " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                    )
                    + (
                        term.bold_bright_white_on_cornflowerblue
                        if commands.index(option) == activeSelection[0]
                        or (
                            commands.index(option) < commands.__len__() - 1
                            and commands.index(option) + 1 == activeSelection[0]
                        )
                        else term.bold_royalblue_on_lightblue
                    )(" ├─────────────────────┤ ")
                    + term.bold_royalblue_on_lightblue(
                        " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                    )
                )
        print(term.royalblue_on_lightblue(lineSpace(1 / 6)))
        activeCmdInfo = commandsInfo[commands[activeSelection[0]]]["info"]
        if type(activeCmdInfo) != str:
            return
        infoLen = len(activeCmdInfo)
        infoSpaceStart = "─" * (infoLen - 12)
        infoSpaceEnd = "─" * (infoLen + 2)
        print(
            term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 3) // 2))
            + term.royalblue_on_lightblue("┌─ Description " + infoSpaceStart + "┐")
            + term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 4) // 2))
        )
        print(
            term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 3) // 2))
            + term.royalblue_on_lightblue("│ " + activeCmdInfo + " │")
            + term.bold_royalblue_on_lightblue(
                " " * (term.width - infoLen - 4 - ((term.width - infoLen - 3) // 2))
            )
        )
        print(
            term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 3) // 2))
            + term.royalblue_on_lightblue("└" + infoSpaceEnd + "┘")
            + term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 4) // 2))
        )
        for i in range(6):
            emptyLine()
        if isCommandEnabled:
            commandSpace = ""
            for _ in range(int((term.width - exitCommand.__len__() - 11))):
                commandSpace += " "
            print(
                term.bold_white_on_green4(" COMMAND ")
                + term.bold_green4_on_gray25(" ")
                + term.bold_bright_white_on_gray25(exitCommand + commandSpace),
                end="",
            )
        else:
            emptyLine("")
        with term.cbreak(), term.hidden_cursor():
            inp = term.inkey()
            if inp.name is not None and inp.name == "KEY_TAB":
                selectedCommand = commands[activeSelection[0]]
                activeSelection.append(0)
                match selectedCommand:
                    case "create-app":
                        isCommandEnabled = False
                        createApp()
                    case "model":
                        pass
                    case "build":
                        pass
                    case _:
                        pass
            else:
                if inp.name is not None and inp.name == "KEY_ESCAPE":
                    isCommandEnabled = True
                elif inp.name is None and isCommandEnabled:
                    exitCommand += inp
                elif (
                    inp.name is not None
                    and isCommandEnabled
                    and inp.name == "KEY_BACKSPACE"
                ):
                    if exitCommand.__len__() > 0:
                        exitCommand = exitCommand[:-1]
                    else:
                        isCommandEnabled = False
                if (
                    inp.name is not None
                    and inp.name == "KEY_ENTER"
                    and isCommandEnabled
                    and exitCommand == ":q"
                ):
                    os.system("clear")
                    exit(0)
                if inp.name is not None and inp.name == "KEY_DOWN":
                    if activeSelection[0] == commands.__len__() - 1:
                        activeSelection[0] = 0
                    else:
                        activeSelection[0] += 1
                if inp.name is not None and inp.name == "KEY_UP":
                    if activeSelection[0] == 0:
                        activeSelection[0] = commands.__len__() - 1
                    else:
                        activeSelection[0] -= 1
                takeInput()
    except KeyboardInterrupt:
        print("Process exited")
        os.system("clear")
        exit(1)


class AppOptions:
    selectedAppOption = "Name"
    InputNumber = 0
    Name = ""
    Desc = ""
    projectName = ""


def __init__(self):
    self.selectedAppOption = "Name"
    self.InputNumber = 0
    self.projectName = ""
    self.Name = ""
    self.Desc = ""


appOptions = AppOptions()


def createApp() -> None:
    try:
        global commandSpace
        global appOptions
        global commands
        global activeSelection
        global isCommandEnabled
        global exitCommand
        global selectedCommand
        os.system("clear")
        term.fullscreen()
        print(term.royalblue_on_lightblue(lineSpace(1 / 6)))
        print(term.cornflowerblue_on_lightblue((logo[1:-1])))
        print(term.royalblue_on_lightblue(lineSpace(1 / 12, True)))
        selectionLabel = "╓── ╓── ╥   ╓── ╓── ─╥─    ╓─╖ ╓╖ ╥ ╓──"
        print(
            term.bold_royalblue_on_lightblue(
                (
                    f"""
{' ' * ((term.width - len(selectionLabel)) // 2)}┏━━ ┏━━ ┳   ┏━━ ┏━━ ━┳━    ┏━┓ ┏┓ ┳ ┏━━{' ' * ((term.width - len(selectionLabel)) // 2)}
{' ' * ((term.width - len(selectionLabel)) // 2)}┗━┓ ┣━━ ┃   ┣━━ ┃    ┃     ┃ ┃ ┃┗┓┃ ┣━━{' ' * ((term.width - len(selectionLabel)) // 2)}
{' ' * ((term.width - len(selectionLabel)) // 2)}━━┛ ┗━━ ┗━━ ┗━━ ┗━━  ┻     ┗━┛ ┻ ┗┛ ┗━━{' ' * ((term.width - len(selectionLabel)) // 2)}"""
                )[1:]
            )
        )
        createAppSubCommands = commandsInfo["create-app"]["subCommands"]
        if type(createAppSubCommands) != dict:
            return
        nameSelected: Callable = (
            term.bold_bright_white_on_royalblue
            if appOptions.selectedAppOption == "Name"
            else term.bold_bright_white_on_cornflowerblue
        )
        nameSelectedBorder: Callable = (
            term.bold_royalblue_on_royalblue
            if appOptions.selectedAppOption == "Name"
            else term.bold_cornflowerblue_on_cornflowerblue
        )
        pathSelected: Callable = (
            term.bold_bright_white_on_royalblue
            if appOptions.selectedAppOption == "Path"
            else term.bold_bright_white_on_cornflowerblue
        )
        pathSelectedBorder: Callable = (
            term.bold_royalblue_on_royalblue
            if appOptions.selectedAppOption == "Path"
            else term.bold_cornflowerblue_on_cornflowerblue
        )
        emptyLine()
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - len("  Name   Path  ")) // 2) - 3)
            )
            + nameSelectedBorder("█" * 10)
            + term.royalblue_on_lightblue(" ")
            + pathSelectedBorder("█" * 10)
            + term.royalblue_on_lightblue(
                " " * (((term.width - len("  Name   Path  ")) // 2) - 3)
            )
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 5)) // 2) - 4)
            )
            + nameSelectedBorder("███")
            + nameSelected("Name")
            + nameSelectedBorder("███")
            + term.bold_royalblue_on_lightblue(" ")
            + pathSelectedBorder("███")
            + pathSelected("Path")
            + pathSelectedBorder("███")
            + term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 5)) // 2) - 4)
            ),
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - len("  Name   Path  ")) // 2) - 3)
            )
            + nameSelectedBorder("██" + (("█" * 6) + "██"))
            + term.royalblue_on_lightblue(" ")
            + pathSelectedBorder("██" + ("█" * 6) + "██")
            + term.royalblue_on_lightblue(
                " " * (((term.width - len("  Name   Path  ")) // 2) - 3)
            )
        )
        emptyLine()
        selectedInfo = createAppSubCommands[appOptions.selectedAppOption]["info"]
        if type(selectedInfo) != str:
            return
        print(
            term.royalblue_on_lightblue(
                " " * ((term.width - len("Description: " + selectedInfo)) // 2)
            ),
            end="",
        )
        print(
            term.bold_royalblue_on_lightblue("Description: ")
            + term.royalblue_on_lightblue(selectedInfo),
            end="",
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - len("Description: " + selectedInfo)) // 2) + 1)
            )
        )
        emptyLine()
        # Project Name/ Path Input
        if appOptions.selectedAppOption != "Path":
            print(
                (
                    term.royalblue_on_lightblue
                    if appOptions.InputNumber == 0
                    else term.cornflowerblue_on_lightblue
                )(
                    (" " * ((term.width - len(" Project Name ") - 20) // 2 + 2))
                    + ("┌─ Project Name " + ("─" * 13) + "┐")
                    + (" " * ((term.width - len(" Project Name ") - 20) // 2 + 3))
                )
            )
            print(
                (
                    term.royalblue_on_lightblue
                    if appOptions.InputNumber == 0
                    else term.cornflowerblue_on_lightblue
                )(
                    (" " * ((term.width - len(" Project Name ") - 20) // 2 + 2))
                    + (
                        "│ "
                        + appOptions.projectName
                        + (" " * (27 - len(appOptions.projectName)))
                        + "│"
                    )
                    + (" " * ((term.width - len(" Project Name ") - 20) // 2 + 3))
                )
            )
            print(
                (
                    term.royalblue_on_lightblue
                    if appOptions.InputNumber == 0
                    else term.cornflowerblue_on_lightblue
                )(
                    (" " * ((term.width - len(" Project Name ") - 20) // 2 + 2))
                    + ("├" + ("─" * 28) + "┤")
                    + (" " * ((term.width - len(" Project Name ") - 20) // 2 + 3))
                )
            )
            print(
                (
                    term.royalblue_on_lightblue
                    if appOptions.InputNumber == 0
                    else term.cornflowerblue_on_lightblue
                )(
                    (" " * ((term.width - len(" Project Name ") - 20) // 2 + 2))
                    + (
                        "│ "
                        + term.bold_royalblue_on_lightblue("Default: ")
                        + "aloo-project"
                        + (" " * (27 - len("Default: aloo-project")))
                        + "│"
                    )
                    + (" " * ((term.width - len(" Project Name ") - 20) // 2 + 3))
                )
            )
            print(
                (
                    term.royalblue_on_lightblue
                    if appOptions.InputNumber == 0
                    else term.cornflowerblue_on_lightblue
                )(
                    (" " * ((term.width - len(" Project Name ") - 20) // 2 + 2))
                    + ("└" + ("─" * 28) + "┘")
                    + (" " * ((term.width - len(" Project Name ") - 20) // 2 + 3))
                )
            )
        # App Name Input
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 1
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - len(" App Name ") - 20) // 2))
                + ("┌─ App Name " + ("─" * 17) + "┐")
                + (" " * ((term.width - len(" App Name ") - 20) // 2 + 1))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 1
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - len(" App Name ") - 20) // 2))
                + ("│ " + appOptions.Name + (" " * (27 - len(appOptions.Name))) + "│")
                + (" " * ((term.width - len(" App Name ") - 20) // 2 + 1))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 1
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - len(" App Name ") - 20) // 2))
                + ("├" + ("─" * 28) + "┤")
                + (" " * ((term.width - len(" App Name ") - 20) // 2 + 1))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 1
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - len(" App Name ") - 20) // 2))
                + (
                    "│ "
                    + term.bold_royalblue_on_lightblue("Default: ")
                    + "Example App"
                    + (" " * (27 - len("Default: Example App")))
                    + "│"
                )
                + (" " * ((term.width - len(" App Name ") - 20) // 2 + 1))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 1
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - len(" App Name ") - 20) // 2))
                + ("└" + ("─" * 28) + "┘")
                + (" " * ((term.width - len(" App Name ") - 20) // 2 + 1))
            )
        )
        # App Description Input
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 2
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - 13 - 40) // 2))
                + ("┌─ Description " + ("─" * 37) + "┐")
                + (" " * ((term.width - 13 - 40) // 2))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 2
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - 13 - 40) // 2))
                + ("│ " + appOptions.Desc + (" " * (50 - len(appOptions.Desc))) + "│")
                + (" " * ((term.width - 13 - 40) // 2))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 2
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - 53) // 2))
                + ("├" + ("─" * 51) + "┤")
                + (" " * ((term.width - 53) // 2))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 2
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - 53) // 2))
                + (
                    "│ "
                    + term.bold_royalblue_on_lightblue("Default: ")
                    + "An default template app for aloo project"
                    + (
                        " "
                        * (
                            50
                            - len("Default: An default template app for aloo project")
                        )
                    )
                    + "│"
                )
                + (" " * ((term.width - 53) // 2))
            )
        )
        print(
            (
                term.royalblue_on_lightblue
                if appOptions.InputNumber == 2
                else term.cornflowerblue_on_lightblue
            )(
                (" " * ((term.width - 53) // 2))
                + ("└" + ("─" * (18 + 33)) + "┘")
                + (" " * ((term.width - 53) // 2))
            )
        )
        emptyLine()
        if appOptions.selectedAppOption == "Path":
            emptyLine()
        print(
            term.royalblue_on_lightblue(" " * ((term.width - 9) // 2))
            + (
                term.royalblue_on_royalblue
                if appOptions.InputNumber == 3
                else term.cornflowerblue_on_cornflowerblue
            )("█" * 9)
            + term.royalblue_on_lightblue(" " * ((term.width - 9) // 2))
        )
        print(
            term.royalblue_on_lightblue(" " * ((term.width - 9) // 2))
            + (
                term.royalblue_on_royalblue
                if appOptions.InputNumber == 3
                else term.cornflowerblue_on_cornflowerblue
            )("██")
            + (
                term.bold_lightblue_on_royalblue
                if appOptions.InputNumber == 3
                else term.bold_lightblue_on_cornflowerblue
            )("Enter")
            + (
                term.royalblue_on_royalblue
                if appOptions.InputNumber == 3
                else term.cornflowerblue_on_cornflowerblue
            )("██")
            + term.royalblue_on_lightblue(" " * ((term.width - 9) // 2))
        )
        print(
            term.royalblue_on_lightblue(" " * ((term.width - 9) // 2))
            + (
                term.royalblue_on_royalblue
                if appOptions.InputNumber == 3
                else term.cornflowerblue_on_cornflowerblue
            )("█" * 9)
            + term.royalblue_on_lightblue(" " * ((term.width - 9) // 2))
        )
        if appOptions.selectedAppOption == "Path":
            emptyLine()
            emptyLine()
            emptyLine()
            emptyLine()
        print(term.royalblue_on_lightblue(lineSpace(1 / 12)))
        if isCommandEnabled:
            commandSpace = ""
            for _ in range(int((term.width - exitCommand.__len__() - 11))):
                commandSpace += " "
            print(
                term.bold_white_on_green4(" COMMAND ")
                + term.bold_green4_on_gray25(" ")
                + term.bold_bright_white_on_gray25(exitCommand + commandSpace),
                end="",
            )
        else:
            emptyLine("")
        with term.cbreak(), term.hidden_cursor():
            inp = term.inkey()
            if isCommandEnabled:
                if inp.name is None:
                    exitCommand += inp
                elif inp.name is not None:
                    if inp.name == "KEY_ENTER" and exitCommand == ":q":
                        os.system("clear")
                        exit(0)
                    elif inp.name == "KEY_BACKSPACE":
                        if exitCommand.__len__() > 0:
                            exitCommand = exitCommand[:-1]
                        else:
                            exitCommand = ""
                            isCommandEnabled = False
            else:
                if inp.name is not None:
                    if inp.name == "KEY_ESCAPE":
                        isCommandEnabled = True
                    elif inp.name == "KEY_LEFT":
                        appOptions.selectedAppOption = "Name"
                    elif inp.name == "KEY_RIGHT":
                        appOptions.selectedAppOption = "Path"
                    elif inp.name == "KEY_DOWN":
                        if appOptions.InputNumber == 3:
                            appOptions.InputNumber = 0
                        else:
                            appOptions.InputNumber += 1
                    elif inp.name == "KEY_UP":
                        if appOptions.InputNumber == 0:
                            appOptions.InputNumber = 3
                        else:
                            appOptions.InputNumber -= 1
                    elif inp.name == "KEY_BACKSPACE":
                        match appOptions.InputNumber:
                            case 1:
                                if appOptions.Name.__len__() > 0:
                                    appOptions.Name = appOptions.Name[:-1]
                                else:
                                    appOptions.Name = ""
                            case 0:
                                if appOptions.projectName.__len__() > 0:
                                    appOptions.projectName = appOptions.projectName[:-1]
                                else:
                                    appOptions.Desc = ""
                            case 2:
                                if appOptions.projectName.__len__() > 0:
                                    appOptions.projectName = appOptions.projectName[:-1]
                                else:
                                    appOptions.projectName = ""
                    elif inp.name == "KEY_ENTER" and appOptions.InputNumber == 3:
                        appInfo = {
                            "app-name": (
                                appOptions.Name
                                if len(appOptions.Name) != 0
                                else "Example App"
                            ),
                            "project-name": (
                                appOptions.projectName
                                if len(appOptions.projectName) != 0
                                else "aloo-project"
                            ),
                            "description": (
                                appOptions.Desc
                                if len(appOptions.Desc) != 0
                                else "An default template app for aloo project"
                            ),
                        }
                        if appOptions.selectedAppOption == "Path":
                            appInfo["project-name"] = os.getcwd().split("/")[-1]
                        if "aloo.config.yaml" in os.listdir(os.getcwd()):
                            os.system("clear")
                            raise FileExistsError("'aloo.config.yaml' already exist")
                        currFilePath = "/".join(__file__.split("/")[:-1])
                        if currFilePath.endswith("bin"):
                            currFilePath = (
                                "/".join(__file__.split("/")[:-2]) + "/etc/aloo/"
                            )
                        projectName = ""
                        if appOptions.selectedAppOption != "Path":
                            projectName = appInfo["app-name"]
                            os.mkdir(appInfo["project-name"])
                            yaml.dump(
                                appInfo,
                                open(
                                    appInfo["project-name"] + "/aloo.config.yaml", "w+"
                                ),
                            )
                            appInfo["project-name"] += "/"
                        else:
                            projectName = os.getcwd().split("/")[-1]
                            yaml.dump(
                                appInfo,
                                open("aloo.config.yaml", "w+"),
                            )
                            appInfo["project-name"] = ""

                        os.mkdir(appInfo["project-name"] + "src")
                        os.mkdir(appInfo["project-name"] + "test")
                        os.system("clear")

                        mainC = open(appInfo["project-name"] + "src/main.c", "w+")
                        testC = open(appInfo["project-name"] + "test/main.c", "w+")
                        CMakeFile = open(
                            appInfo["project-name"] + "CMakeLists.txt", "w+"
                        )

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

                        mainCSample = mainCSample.replace(
                            "$projectName", projectName
                        ).replace("$appName", appInfo["app-name"])
                        mainC.write(mainCSample)

                        testCSample = testCSample.replace(
                            "$projectName", projectName
                        ).replace("$appName", appInfo["app-name"])
                        testC.write(testCSample)

                        CMakeSample = CMakeSample.replace(
                            "$appName", appInfo["app-name"]
                        ).replace("$include_dir", alooDir + "include")
                        CMakeSample = CMakeSample.replace(
                            "$libaloo", alooDir + "lib"
                        ).replace("$libaloo", alooDir + "lib")
                        CMakeFile.write(CMakeSample)

                        print("\t\033[1;32m󰄭 Aloo project created successfully\033[0m")
                        exit(0)
                else:
                    match appOptions.InputNumber:
                        case 0:
                            appOptions.projectName += inp
                        case 1:
                            appOptions.Name += inp
                        case 2:
                            appOptions.Desc += inp
            createApp()
    except KeyboardInterrupt:
        print("Process exited")
        os.system("clear")
        exit(1)


if __name__ == "__main__":
    term = blessed.Terminal()
    spaces: str = " "
    for i in range(
        int((term.width - len("████████║  ██║      ██║      ██║  ██║      ██║")) / 2)
        - 1
    ):
        spaces += " "

    alooTypes = Union["str", "int", "float", "bool", "object"]
    commands: list[str] = ["create-app", "model", "build", "run", "connect-db"]
    commandsInfo = {
        "create-app": {
            "info": "Create a new C aloo app",
            "hasSubCommands": True,
            "subCommands": {
                "Name": {
                    "info": "Create new project with name         ",
                    "field": {
                        "projectName": str,
                        "appName": str,
                        "description": Optional[str],
                    },
                },
                "Path": {
                    "info": "Uses current directory as new project",
                    "field": {
                        "projectPath": str,
                        "appName": str,
                        "description": Optional[str],
                    },
                },
            },
        },
        "model": {
            "info": "Create a new model",
            "hasSubCommands": False,
            "fields": {"name": str, "field": dict[str, alooTypes]},
        },
        "build": {
            "info": "Build the aloo project",
            "hasSubCommands": False,
        },
        "run": {
            "info": "Runs the project app/ tests",
            "hasSubCommands": True,
            "subCommands": {
                "app": {"fields": "Runs the aloo app"},
                "test": {"fields": "Runs the aloo project tests"},
            },
        },
        "connect-db": {
            "info": "Works with connection with databases",
            "hasSubCommands": True,
            "subCommands": {
                "new": {
                    "info": "Create a new connection with database",
                    "field": {"modelName": str},
                },
                "restart": {
                    "info": "Deletes all data from sqlite",
                    "field": {"modelName": str},
                },
                "add": {
                    "info": "Add database model",
                    "field": {"modelName": str},
                },
            },
        },
    }

    activeSelection = [0]
    print(term.home + term.clear + term.move_y(term.height))

    logo = f"""
    {spaces} ██████╗   ██╗         █████╗        █████╗    {spaces}
    {spaces}██╔═══██║  ██║       ██║    ██╗    ██║    ██╗  {spaces}
    {spaces}████████║  ██║      ██║      ██║  ██║      ██║ {spaces}
    {spaces}██║   ██║  ██║       ██║    ██╝    ██║    ██╝  {spaces}
    {spaces}██║   ██║  ██████║     █████╝        █████╝    {spaces}
    """

    os.system("clear")
    term.fullscreen()

    exitCommand = ""
    isCommandEnabled = False
    selectedCommand = ""
    commandSpace: str = ""
    takeInput()