# CLI

**It consists of 2 commands:**

## `aloo-cli`

It's just basic aloo CLI.

## `aloo`

It contains aloo CLI + TUI by ftxui

## Commands

### `create-app`

Create a new aloo app default template

#### How to use

##### With --name Flag

```bash
aloo create-app --name <projectName>
ls -a
cd <projectName>
tree
```

Options with default values

```bash
Enter app name[Example App]:
Enter description[An default template for aloo App]:
'<projectName>' template app created successfully 
.  ..  <projectName>
.
├── aloo.json
├── app
│   └── main.c
├── CMakeLists.txt
└── test
    └── main.c

3 directories, 5 files
```

##### With --path Flag

```bash
aloo create-app --path ..
cd ..
tree
```

Options with default values

```bash
Enter app name[Example App]:
Enter description[An default template for aloo App]:
'<projectName>' template app created successfully 
.  ..  aloo.json app CMakeLists.txt test ...
.
├── aloo.json
├── app
│   └── main.c
├── CMakeLists.txt
└── test
│   └── main.c
└...

3 directories, 5 files
```

##### With No Flags

```bash
aloo create-app
ls -a
```

Options with default values

```bash
Enter project name[aloo-project]:
Enter app name[Example App]:
Enter description[An default template for aloo App]:
'<projectName>' template app created successfully 
.  ..  <projectName>
```

### `connect-db`

Connect to specified database

> ![NOTE]
> Database connection with mongodb has not been implemented yet

#### SQLite

##### Create new sqlite database

```bash
aloo connect-db sqlite3 new <dbName>.<sqlite|db>
```

##### Delete all data

```bash
aloo connect-db sqlite3 restart
```

##### Create utils for model

```bash
aloo connect-db sqlite3 add <modelName>
```
