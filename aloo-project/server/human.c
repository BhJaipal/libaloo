#include "human.h"
#include "db/sqlite.h"
#include <string.h>

human *out;

int str_to_int(char *str) {
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ') { i++; }
	if (str[i] == '-' || str[i] == '+') {
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * sign;
}

void createhumanTable(sqlite3 *db) {
	char *err;
	SQLite.createTable(db, "human", "ID INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT", &err);
	if (err) printf("%s\n", err);
}

human *selecthuman(sqlite3 *db, char *where) {
	out = malloc(sizeof(human) * 0);
	char errmsg[1024];
	char cols = {"ID", "name"};
	int result =
		SQLite.select(db, "Human", 1, cols, where, callback, &errmsg);
	if (result != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", errmsg);
		return NULL;
	}
	return out;
}
void inserthuman(sqlite3 *db, int column_count, char **values,
					  char **errmsg) {
	SQLite.insert(db, "human", column_count, "name", values, errmsg);
}

int callback(void *data, int col_count, char **values, char **column_names) {
	human val;
	int i = 0;
	val.id = values[i++];
	val.name = values[i++];
	out = realloc(out, sizeof(out) + (sizeof(out[0])));
	return 0;
}
