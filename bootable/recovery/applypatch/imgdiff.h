

// Image patch chunk types
#define CHUNK_NORMAL   0
#define CHUNK_GZIP     1   // version 1 only
#define CHUNK_DEFLATE  2   // version 2 only
#define CHUNK_RAW      3   // version 2 only

// The gzip header size is actually variable, but we currently don't
// support gzipped data with any of the optional fields, so for now it
// will always be ten bytes.  See RFC 1952 for the definition of the
// gzip format.
#define GZIP_HEADER_LEN   10

// The gzip footer size really is fixed.
#define GZIP_FOOTER_LEN   8
