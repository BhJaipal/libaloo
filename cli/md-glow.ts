#!/home/jaipal001/.bun/bin/bun

import { readFileSync } from "fs";
import process from "process";

let src = process.cwd() + "/" + process.argv[2];

let srcContent = readFileSync(src).toString();
let srcArray = srcContent.split("\n");

let style = {
	reset: "0",
	black: "30",
	green: "32",
	red: "31",
	blue: "34",
	purple: "35",
	yellow: "33",
	cyan: "36",
	white: "37",
	bgBlack: "40",
	bgRed: "41",
	bgGreen: "42",
	bgYellow: "43",
	bgBlue: "44",
	bgPurple: "45",
	bgCyan: "46",
	bgWhite: "47",
	bgGrey: "100",
	grey: "90",
	bold: "1",
	light: "2",
	italic: "3",
	underline: "4",
	reverse: "7",
};
function colorIt(...cl: string[]) {
	return (
		"\x1b[" +
		cl.slice(0, cl.length - 1).join(";") +
		`m${cl[cl.length - 1]}\x1b[0m`
	);
}

let dictStart = false;
let dict: { [key: string]: string } = {};
for (let element of srcArray) {
	if (!element.length) console.log();

	if (element.startsWith("---")) {
		if (dictStart) {
			let key = Object.keys(dict).reduce((prev, curr) =>
				curr.length + dict[curr].length >
				prev.length + dict[prev].length
					? curr
					: prev
			);
			let startPrint =
				"┌" + ("─".repeat(key.length + dict[key].length + 5) + "┐");
			startPrint =
				startPrint.slice(0, key.length + 3) +
				"┐┌" +
				startPrint.slice(key.length + 4);
			console.log(startPrint);
			for (const k of Object.keys(dict)) {
				console.log(
					"│ " +
						(k.length != key.length
							? " ".repeat(
									Math.floor((key.length - k.length) / 2)
							  ) +
							  k +
							  " ".repeat(Math.ceil((key.length - k.length) / 2))
							: key) +
						" ││ " +
						dict[key] +
						" │"
				);
			}
			startPrint =
				"└" + ("─".repeat(key.length + dict[key].length + 5) + "┘");
			startPrint =
				startPrint.slice(0, key.length + 3) +
				"┘└" +
				startPrint.slice(key.length + 4);
			console.log(startPrint);

			dictStart = false;
			dict = {};
		} else {
			dictStart = true;
		}
		continue;
	}
	if (dictStart) {
		dict[element.split(":")[0].trim()] = element.split(":")[1].trim();
		continue;
	}
	let headingCheck = element.match(/#+ /);
	if (headingCheck) {
		let name = element.split(" ").slice(1).join(" ");
		header(name, headingCheck[0].split(" ")[0].length);
		continue;
	}
	if (
		(element.startsWith("**") && element.endsWith("**")) ||
		(element.startsWith("__") && element.endsWith("__"))
	) {
		let out = element.slice(2, element.length - 2);
		console.log(colorIt(style.bold, out));
		continue;
	}
	if (element.startsWith("`") && element.endsWith("`")) {
		let out = element.slice(1, element.length - 1);
		console.log(
			colorIt(style.italic, style.bold, style.bgGrey, style.green, out)
		);
		continue;
	}
	if (element.startsWith("*") && element.endsWith("*")) {
		let out = element.slice(1, element.length - 1);
		console.log(colorIt(style.italic, out));
		continue;
	}
	if (element.startsWith("- ")) {
		list(element.slice(2).trim());
		continue;
	}
	console.log(element);
}

/**
 *
 * @param element string
 * @param depth if there's another list inside list
 */
function list(element: string, depth: number = 0) {
	let tabs = "\t".repeat(depth);

	if (element.startsWith("- ")) {
		element = element.slice(2);
		list(element, depth + 1);
	} else if (
		(element.startsWith("**") && element.slice(2).includes("**")) ||
		(element.startsWith("__") && element.slice(2).includes("__"))
	) {
		let out = element.slice(
			2,
			element.slice(2).includes("**")
				? element.slice(2).indexOf("**") + 2
				: element.slice(2).indexOf("__") + 2
		);

		let remaining = element.slice(out.length + 4);
		console.log(tabs, "•", colorIt(style.bold, out) + code(remaining));
	} else if (element.includes("`")) {
		console.log(tabs, "•", code(element));
	} else console.log(tabs, "•", element);
}

/**
 *
 * @param element heading string
 * @param size heading type (1-5)
 *
 * @example
 * ```js
 * header("Hello", (1-5));
 * ```
 * @concept on size > 5, it will go for white bg + black text
 */
function header(element: string, size: number = 1) {
	element = ` ${element}${"    ".repeat(10 - size)}`;

	switch (size) {
		case 1:
			console.log("\t", colorIt(style.bold, style.bgBlue, element));
			break;
		case 2:
			console.log("\t", colorIt(style.bold, style.bgPurple, element));
			break;
		case 3:
			console.log("\t", colorIt(style.bold, style.bgRed, element));
			break;
		case 4:
			console.log("\t", colorIt(style.bold, style.bgYellow, element));
			break;
		case 5:
			console.log("\t", colorIt(style.bold, style.bgGreen, element));
			break;
		default:
			console.log("\t", colorIt(style.bold, style.bgWhite, element));
			break;
	}
}

function code(str: string) {
	let codeIn = -1;
	let codeOut = -1;
	for (let i = 0; i < str.length; i++) {
		const element = str[i];
		if (element == "`" && codeIn == -1) {
			codeIn = i;
			continue;
		} else if (element == "`" && codeIn != -1) {
			codeOut = i;
			let codeBlock = colorIt(
				style.italic,
				style.bold,
				style.bgGrey,
				style.green,
				str.slice(codeIn + 1, codeOut)
			);
			str = str.slice(0, codeIn) + codeBlock + element.slice(codeOut + 1);
			codeIn = -1;
			codeOut = -1;
			continue;
		}
	}
	return str;
}
