struct dnode *l_insert(struct dnode *l, char *key);
struct dnode *l_find(struct dnode *l, char *key);
int32 hash65(char *key);
void hash_insert(struct dnode **hTab, int maxHash, char *key);
struct dnode *hash_find(struct dnode **hTab, int maxHash, char *key);
void Hash(int *data, int *target, int d, int q);