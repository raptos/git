#ifndef ODB_HELPER_H
#define ODB_HELPER_H

/*
 * An odb helper is a way to access a remote odb.
 *
 * Information in its fields comes from the config file [odb "NAME"]
 * entries.
 */
struct odb_helper {
	const char *name;                 /* odb.<NAME>.* */
	const char *remote;               /* odb.<NAME>.promisorRemote */

	struct odb_helper *next;
};

extern struct odb_helper *odb_helper_new(const char *name, int namelen);
extern int odb_helper_get_direct(struct odb_helper *o,
				 const unsigned char *sha1);
#endif /* ODB_HELPER_H */
