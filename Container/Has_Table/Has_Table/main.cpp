#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "hash.h"
void testHash(HashTable *ht)
{
	const char* key[] = { "a", "b", "c", "d", "e", "f" };
	const char* value[] = { "value1", "value2", "value3", "value4", "value5", "value6" };
	for (int i = 0; i < 6; ++i)
	{
		ht->install(key[i], value[i]);
	}
}
int main(int argc, char const *argv[])
{
	HashTable ht;
	testHash(&ht);
	ht.display();
	system("pause");
	return 0;
}
//出现内存冲突的问题；
