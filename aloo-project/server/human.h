#include "../models/human.h"
#include "db/sqlite.h"

int str_to_int(char *str);

void createhumanTable(sqlite3 *db);
human *selecthuman(sqlite3 *db, char *where);
void inserthuman(sqlite3 *db, int column_count, char **values,
					  char **errmsg);

int callback(void *data, int col_count, char **values, char **column_names);
