import blessed
import os
from typing import Union, Optional

term = blessed.Terminal()
spaces: str = " "
for i in range(
    int((term.width - len("████████║  ██║      ██║      ██║  ██║      ██║")) / 2) - 1
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
                "info": "Name of the new project",
                "field": {
                    "projectName": str,
                    "appName": str,
                    "description": Optional[str],
                },
            },
            "Path": {
                "info": "Path of the new project",
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
        "fields": {"name": str, "field": list[str, alooTypes]},
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


def lineSpace(n: float = 1 / 4, isEnd=False):
    lineSpaces = ""
    global commands
    for i in range(int(n * (term.height - 5))):
        lineSpaces += " "
        for _ in range(term.width - 1):
            lineSpaces += " "
        lineSpaces += "\n"
    lineSpaces = lineSpaces[:-1]
    return lineSpaces


activeSelection = [0]
print(term.home + term.clear + term.move_y(term.height))

logo = f"""
{spaces} ██████╗   ██╗         █████╗        █████╗    {spaces}
{spaces}██╔═══██║  ██║       ██╔════██╗    ██╔════██╗  {spaces}
{spaces}████████║  ██║      ██║      ██║  ██║      ██║ {spaces}
{spaces}██║   ██║  ██║       ██╚════██╝    ██╚════██╝  {spaces}
{spaces}██║   ██╝  ██████║     █████╝        █████╝    {spaces}
"""

os.system("clear")
term.fullscreen()

exitCommand = ""
isCommandEnabled = False
selectedCommand = ""


def takeInput():
    try:
        global commands
        global activeSelection
        global isCommandEnabled
        global exitCommand
        global selectedCommand
        os.system("clear")
        term.fullscreen()
        print(term.royalblue_on_lightblue(lineSpace(1 / 6)))
        print(term.royalblue_on_lightblue((logo[1:-1])))
        print(term.royalblue_on_lightblue(lineSpace(1 / 5, True)))
        for option in commands:
            if commands.index(option) == 0:
                print(
                    term.bold_royalblue_on_lightblue(
                        " " * ((term.width - len(" ┌─────────────────────┐ ")) // 2)
                    )
                    + (
                        term.bold_white_on_royalblue
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
                    term.bold_bright_white_on_royalblue
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
                        term.bold_bright_white_on_royalblue
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
                        term.bold_bright_white_on_royalblue
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
        infoLen = len(commandsInfo[commands[activeSelection[0]]]["info"])
        infoSpaceStart = "─" * (infoLen - 12)
        infoSpaceEnd = "─" * (infoLen + 2)
        print(
            term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 3) // 2))
            + term.royalblue_on_lightblue("┌─ Description " + infoSpaceStart + "┐")
            + term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 4) // 2))
        )
        print(
            term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 3) // 2))
            + term.royalblue_on_lightblue(
                "│ " + commandsInfo[commands[activeSelection[0]]]["info"] + " │"
            )
            + term.bold_royalblue_on_lightblue(
                " " * (term.width - infoLen - 4 - ((term.width - infoLen - 3) // 2))
            )
        )
        print(
            term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 3) // 2))
            + term.royalblue_on_lightblue("└" + infoSpaceEnd + "┘")
            + term.bold_royalblue_on_lightblue(" " * ((term.width - infoLen - 4) // 2))
        )
        print(term.royalblue_on_lightblue(lineSpace()))
        if isCommandEnabled:
            commandSpace = ""
            for _ in range(int((term.width - exitCommand.__len__() - 11))):
                commandSpace += " "
            print(
                term.bold_white_on_green4(" COMMAND ")
                + term.bold_green4_on_gray25(" ")
                + term.bold_bright_white_on_gray25(exitCommand + commandSpace)
            )
        with term.cbreak(), term.hidden_cursor():
            inp = term.inkey()
            if inp.name is not None and inp.name != "KEY_TAB":
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
            else:
                selectedCommand = commands[activeSelection[0]]
                activeSelection.append(0)
                match selectedCommand:
                    case "create-app":
                        createApp()
                    case "model":
                        pass
                    case "build":
                        pass
                    case _:
                        pass
    except KeyboardInterrupt:
        print("Process exited")
        os.system("clear")
        exit(1)


def createApp():
    try:
        global commandSpace
        global commands
        global activeSelection
        global isCommandEnabled
        global exitCommand
        global selectedCommand
        os.system("clear")
        term.fullscreen()
        print(term.royalblue_on_lightblue(lineSpace(1 / 6)))
        print(term.royalblue_on_lightblue((logo[1:-1])))
        print(term.royalblue_on_lightblue(lineSpace(1 / 5, True)))
        print(
            term.bold_royalblue_on_lightblue(
                f"{' ' * ((term.width - 10) // 2)}Select one{' ' * ((term.width - 10) // 2 + 1)}"
            )
        )
        createAppSubCommands: dict[str, dict[str, Union[str, dict[str, object]]]] = (
            commandsInfo["create-app"]["subCommands"]
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 5)) // 2) - 1)
            ),
            end="",
        )
        print(
            term.royalblue_on_lightblue("┌"),
            end="",
        )
        print(
            term.bold_royalblue_on_lightblue(
                "─" * (len("Name") + 2) + "ᚁ" + "─" * (len("Path") + 2)
            ),
            end="",
        )
        print(
            term.royalblue_on_lightblue("┐"),
            end="",
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 5)) // 2) - 1)
            )
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 5)) // 2) - 1)
            ),
            end="",
        )
        print(term.bold_royalblue_on_lightblue("│ Name │ Path │"), end="")
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 5)) // 2) - 1)
            ),
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 4)) // 2) - 1)
            ),
            end="",
        )
        print(
            term.royalblue_on_lightblue("└"),
            end="",
        )
        print(
            term.bold_royalblue_on_lightblue(
                "─" * (len("Name") + 2) + "ᚆ" + "─" * (len("Path") + 2)
            ),
            end="",
        )
        print(
            term.royalblue_on_lightblue("┘"),
            end="",
        )
        print(
            term.royalblue_on_lightblue(
                " " * (((term.width - (len("NamePath") + 5)) // 2) - 1)
            )
        )
        print(term.royalblue_on_lightblue(lineSpace(1 / 2)))
        if isCommandEnabled:
            commandSpace = ""
            for _ in range(int((term.width - exitCommand.__len__() - 11))):
                commandSpace += " "
            print(
                term.bold_white_on_green4(" COMMAND ")
                + term.bold_green4_on_gray25(" ")
                + term.bold_bright_white_on_gray25(exitCommand + commandSpace)
            )
        with term.cbreak(), term.hidden_cursor():
            inp = term.inkey()
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
            createApp()
    except KeyboardInterrupt:
        print("Process exited")
        os.system("clear")
        exit(1)


if __name__ == "__main__":
    takeInput()
