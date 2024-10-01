import blessed
import os

term = blessed.Terminal()
spaces: str = " "
for i in range(
    int((term.width - len("████████║  ██║      ██║      ██║  ██║      ██║")) / 2) - 1
):
    spaces += " "

commands: str = ""


def lineSpace(n: float = 1 / 4, isEnd=False):
    lineSpaces = ""
    global commands
    for i in range(
        int(n * (term.height - 5)) - (0 if commands == "" or not isEnd else 2)
    ):
        lineSpaces += " "
        for _ in range(term.width - 1):
            lineSpaces += " "
        lineSpaces += "\n"
    lineSpaces = lineSpaces[:-1]
    return lineSpaces


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
print(term.blue_on_lightblue(lineSpace()))
print(term.blue_on_lightblue((logo[1:-1])))
print(term.blue_on_lightblue(lineSpace(3 / 4)))


def takeInput():
    try:
        global commands
        if commands != "":
            os.system("clear")
            term.fullscreen()
            print(term.blue_on_lightblue(lineSpace()))
            print(term.blue_on_lightblue((logo[1:-1])))
            if commands.__len__() != 0:
                print(term.blue_on_lightblue(lineSpace(1 / 5, True)))
                print(
                    term.bold_blue_on_lightblue(term.center("┌─────────────────────┐"))
                )
                print(
                    term.bold_blue_on_lightblue(
                        term.center("│ " + commands + " " * (20 - len(commands)) + "│")
                    )
                )
                print(
                    term.bold_blue_on_lightblue(term.center("└─────────────────────┘"))
                )
                print(term.blue_on_lightblue(lineSpace(1 / 2)))
            else:
                print(term.blue_on_lightblue(lineSpace(3 / 4)))
        with term.cbreak(), term.hidden_cursor():
            inp = term.inkey()
            if ord(inp) == 27:
                commands = ""
                takeInput()
            if ord(inp) >= 32 and ord(inp) <= 126:
                commands += inp
            if inp.name == "KEY_BACKSPACE":
                if commands.__len__() == 1:
                    commands = ""
                elif commands.__len__() > 1:
                    commands = commands[:-1]
                takeInput()
            if inp.name == "KEY_ENTER":
                print(commands)
                if commands != ":q":
                    takeInput()
                else:
                    os.system("clear")
                    exit(0)
            else:
                term.clear
                takeInput()
    except KeyboardInterrupt:
        print("Process exited")
        os.system("clear")
        exit(1)


takeInput()
