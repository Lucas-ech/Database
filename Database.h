#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <stdexcept>
#include <sqlite3.h>
#include <fstream>

class Database {

	public:
		Database(const char* dbfile);
		~Database();
		bool isEmpty() const;
		int request(const char* req, int (*callback)(void*,int,char**,char**), void* firstArg = NULL);

	private:
		sqlite3 *m_db;
		char *m_error;
		bool m_isEmpty;

};

#endif