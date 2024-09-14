if [ $2 = "app" ]; then
	if [ -f bin/app.exe ]; then
		./bin/app.exe
	else
		echo -e "\033[1;31mError:\033[0m No executable found, please build app first"
	fi
elif [ $2 = "test" ]; then
	if [ -f bin/test.exe ]; then
		cd build && ctest -C Release && cd ..
	else
		echo -e "\033[1;31mError:\033[0m No executable found, please build test first"
	fi
else
	echo -e "\033[1;31mError:\033[0m Invalid argument.\n\tPlease provide either 'app' or 'test' as an argument."
fi
