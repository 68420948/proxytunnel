/* Proxytunnel - (C) 2001-2008 Jos Visser / Mark Janssen    */
/* Contact:                  josv@osp.nl / maniac@maniac.nl */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* cmdline.h */
/* File autogenerated by gengetopt version 2.4 - Modified by Maniac */

#ifndef _cmdline_h
#define _cmdline_h

#define MAX_HEADER_SIZE 1024

struct gengetopt_args_info {
	char *user_arg;			/* Username to send to HTTPS proxy for auth. */
	char *pass_arg;			/* Password to send to HTTPS proxy for auth. */
	char *remuser_arg;		/* Username to send to remote HTTPS proxy for auth. */
	char *rempass_arg;		/* Password to send to remote HTTPS proxy for auth. */
	char *domain_arg;		/* NTLM Domain override */
	char *proxy_arg;		/* HTTPS Proxy host to connect to. */
	char *proxyauth_arg;	/* Local proxy auth. */
	char *proxyhost_arg;	/* HTTPS Proxy host to connect to. */
	int proxyport_arg;		/* HTTPS Proxy host portnumber to connect to. */
	char *dest_arg;			/* Destination host to built the tunnel to. */
	char header_arg[MAX_HEADER_SIZE];	/* Extra headers to send to proxy */
	char *remproxy_arg;		/* Remote proxy to tunnel to. */
	char *remproxyauth_arg;	/* Remote proxy auth. */
	int verbose_flag;		/* Turn on verbosity (default=off). */
	int quiet_flag;			/* Turn on quiet mode (default=off). */
	int ntlm_flag;			/* Turn on ntlm  (default=off). */
	int inetd_flag;			/* Turn on inetd (default=off). */
	char *standalone_arg;	/* Turn on standalone (-a) on [addr:]port */
	char *standalone_addr;
	char *standalone_iface;
	int standalone_port;
	int encrypt_flag;		/* Turn on SSL encryption (default=off). */
	int encryptproxy_flag;	/* Turn on client to proxy SSL encryption (def=off).*/
	int encryptremproxy_flag;  /* Turn on local to remote proxy SSL encryption (def=off).*/
	char *clientcert_arg;	/* client SSL certificate */
	char *clientkey_arg;	/* client SSL key */
	int wa_bug_29744_flag;	/* Use SSL encryption only until CONNECT, if at all (def=off).*/
	int no_ssl3_flag;		/* Turn off SSLv3 (default=on) */
	char *proctitle_arg;	/* Override process title (default=off). */
	int enforcetls1_flag;    /* Override default and enforce TLSv1 */
	char *host_arg;         /* Optional Host Header */
	int no_check_cert_flag;	/* Turn off server SSL certificate verification (default=on) */
	int enforceipv4_flag;   /* Enforce IPv4 (default=off). */
	int enforceipv6_flag;   /* Enforce IPv6 (default=off). */
	char *cacert_arg; 		/* Trusted CA certificate (or directory) for server SSL certificate verification */
	int help_given;			/* Whether help was given. */
	int version_given;		/* Whether version was given. */
	int user_given;			/* Whether user was given. */
	int pass_given;			/* Whether pass was given. */
	int remuser_given;		/* Whether remote user was given. */
	int rempass_given;		/* Whether remote pass was given. */
	int domain_given;		/* Whether domain was given. */
	int proxy_given;		/* Whether proxyhost was given. */
	int proxyauth_given;	/* Whether proxyhost was given. */
	int proxyhost_given;	/* Whether proxyhost was given. */
	int proxyport_given;	/* Whether proxyport was given. */
	int dest_given;			/* Whether dest was given. */
	int remproxy_given;		/* Whether remproxy was given. */
	int remproxyauth_given;	/* Whether remproxy was given. */
	int verbose_given;		/* Whether verbose was given. */
	int quiet_given;		/* Whether quiet mode was given. */
	int ntlm_given;			/* Whether ntlm was given. */
	int inetd_given;		/* Whether inetd was given. */
	int standalone_given;	/* Whether standalone was given */
	int standalone_addr_given;	/* Whether standalone address was given */
	int standalone_iface_given;	/* Whether standalone interface was given */
	int header_given;		/* Whether extra headers are given */
	int encrypt_given;		/* Whether encrypt was given */
	int encryptproxy_given;	/* Whether encrypt was given */
	int encryptremproxy_given;   /* Whether encrypt was given */
	int clientcert_given;	/* Whether client SSL certificate was given */
	int clientkey_given;	/* Whether client SSL key was given */
	int wa_bug_29744_given;	/* Whether work around was given */
	int proctitle_given;	/* Whether to override process title */
	int enforcetls1_given;   /* Wheter to enforce TLSv1 */
	int host_given;         /* Wheter we override the Host Header */
	int cacert_given;		/* Whether cacert was given */
};

int cmdline_parser( int argc, char * const *argv, struct gengetopt_args_info *args_info );

void cmdline_parser_print_help( void );
void cmdline_parser_print_version( void );

#endif /* _cmdline_h */

// vim:noexpandtab:ts=4
