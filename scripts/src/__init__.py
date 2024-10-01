import blessed
import os

term = blessed.Terminal()
spaces = " "
for i in range(int((term.width - len("████████║  ██║      ██║      ██║  ██║      ██║"))/2)-1):
	spaces += " "

def lineSpace(n=1):
	lineSpaces = ""
	for i in range(n*(term.height-5)//4):
		lineSpaces += " "
		for _ in range(term.width-1):
			lineSpaces += " "
		lineSpaces += "\n"
	lineSpaces= lineSpaces[:-1]

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
print(term.blue_on_lightblue(lineSpace(3)))
commands = ""

def takeInput():
	try:
		with term.cbreak(), term.hidden_cursor():
			inp = term.inkey()
			if inp == ":":
				global commands
				commands+= ":"
			if inp != "q":
				takeInput()
			else:
				term.clear
	except KeyboardInterrupt:
		print("Process exited")
		exit(1)

takeInput()
os.system("clear")
