typedef struct {
	char* key;
	listint_t node;
} ht_item;

typedef struct {
	int size;
	int count;
	ht_item** item;
} ht_hash_table;
