import blessed

term = blessed.Terminal()
spaces = " "
for i in range(int(term.width/3)+7):
	spaces += " "
print(term.home + term.clear + term.move_y(term.height // 2))
logo = f"""{spaces} ██████╗   ██╗         █████╗        █████╗   {spaces}
{spaces}██╔═══██║  ██║       ██╔════██╗    ██╔════██╗ {spaces}
{spaces}████████║  ██║      ██║      ██║  ██║      ██║{spaces}
{spaces}██║   ██║  ██║       ██╚════██╝    ██╚════██╝ {spaces}
{spaces}██║   ██╝  ██████║     █████╝        █████╝   {spaces}"""

print(term.blue_on_lightblue(term.center(logo)))

try:
	while True:
		with term.cbreak(), term.hidden_cursor():
			inp = term.inkey()
			if inp == ":q": break
except KeyboardInterrupt:
	print("Process exited")
	exit(1)
