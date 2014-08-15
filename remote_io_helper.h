
struct remote_io_helper {

	int listener;
	int encryption;
	
	int local_fd;
	int remote_fd;

	char *ip_addr;

	BIO *connect;
  SSL_CTX *ctx;
  SSL *ssl;
  DH *dh;

	int (*remote_read)(struct remote_io_helper *io, void *buf, size_t count);
	int (*remote_write)(struct remote_io_helper *io, void *buf, size_t count);
	int (*remote_printf)(struct remote_io_helper *io, char *fmt, ...);

};