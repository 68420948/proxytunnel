
[![Build Status](https://travis-ci.org/proxytunnel/proxytunnel.svg?branch=master)](https://travis-ci.org/proxytunnel/proxytunnel)
[![Maintainers Wanted](https://img.shields.io/badge/maintainers-wanted-red.svg)](https://github.com/pickhardt/maintainers-wanted)


# Proxytunnel

Author:		Jos Visser <josv@osp.nl>, Mark Janssen <maniac@maniac.nl>

Hi all,

This is proxytunnel, a program that connects stdin and stdout
to an origin server somewhere in the Internet through an industry
standard HTTPS proxy. I originally wrote this program to be used
as an extension to SSH, to be able to SSH to my box at home. In 
this file, I will describe the use with SSH. If you want to use it
with some other application, feel free, and let me know!

# Build docs is [here](INSTALL.md) 

# Usage (man page is [here](docs/proxytunnel.1.adoc)):

Proxytunnel is very easy to use, when running proxytunnel with the help
option it specifies it's command-line options.

```
$ ./proxytunnel --help
proxytunnel 1.9.9 Copyright 2001-2018 Proxytunnel Project
Usage: proxytunnel [OPTIONS]...
Build generic tunnels through HTTPS proxies using HTTP authentication

Standard options:
 -i, --inetd                Run from inetd (default: off)
 -a, --standalone=INT       Run as standalone daemon on specified port
 -p, --proxy=STRING         Local proxy host:port combination
 -r, --remproxy=STRING      Remote proxy host:port combination (using 2 proxies)
 -d, --dest=STRING          Destination host:port combination
 -e, --encrypt              SSL encrypt data between local proxy and destination
 -E, --encrypt-proxy        SSL encrypt data between client and local proxy
 -X, --encrypt-remproxy     SSL encrypt data between local and remote proxy
 -W, --wa-bug-29744         workaround ASF Bugzilla 29744, if SSL is active stop
                            using it after CONNECT (might not work on all setups;
                            see /usr/share/doc/proxytunnel/README.Debian.gz)
 -B, --buggy-encrypt-proxy  Equivalent to -E -W, provided for backwards
                            compatibility
 -L                         (legacy) enforce TLSv1 connection
 -T, --no-ssl3              Do not connect using SSLv3

Additional options for specific features:
 -z, --no-check-certificate Don't verify server SSL certificate
 -C, --cacert=STRING        Path to trusted CA certificate or directory
 -F, --passfile=STRING      File with credentials for proxy authentication
 -P, --proxyauth=STRING     Proxy auth credentials user:pass combination
 -R, --remproxyauth=STRING  Remote proxy auth credentials user:pass combination
 -N, --ntlm                 Use NTLM based authentication
 -t, --domain=STRING        NTLM domain (default: autodetect)
 -H, --header=STRING        Add additional HTTP headers to send to proxy
 -o STRING                  send custom Host Header
 -x, --proctitle=STRING     Use a different process title

Miscellaneous options:
 -v, --verbose              Turn on verbosity
 -q, --quiet                Suppress messages
 -h, --help                 Print help and exit
 -V, --version              Print version and exit
```

To use this program with OpenSSH to connect to a host somewhere, create
a $HOME/.ssh/config file with the following content:

```
Host foobar
	ProtocolKeepAlives 30
	ProxyCommand /path/to/proxytunnel -E -p proxy:8080 -P username -d mybox.athome.nl:443
```

With:

```
- foobar		The symbolic name of the host you want to connect to
- -E			Option to use encryption to communicate to the proxy (use https)
- proxy			The host name of the proxy you want to connect through
- 8080			The port number where the proxy software listens to
- username		Your proxy userid (password will be prompted)
- mybox.athome.nl	The hostname of the box you want to connect to (ultimately)
- 443			The port number of the SSH daemon on mybox.athome.nl
```

Optional arguments:
```
- -z			Don't verify server SSL certificate (for example in case of self-signed certificate)
```

If your proxy doesn't require the username and password for using it,
you can skip these options. If you don't provide the password on the
command-line (which is recommended) you will be prompted for it by
proxytunnel. If you are on a trusted system you can also put the
password in the environment variable PROXYPASS.

If you want to run proxytunnel from inetd add the '--inetd' option.

Most HTTPS proxies do not allow access to ports other than 443 (HTTPS)
and 563 (SNEWS), so some hacking is necessary to start the SSH daemon on
the required port. (On the server side add an extra Port statement in
the sshd_config file, or use a redirect rule in your firewall.)

When your proxy uses NTLM authentication (like Microsoft IIS proxy)
you need to specify -N to enable NTLM, and then specify your username
and password (and optionally domain, if autodetection fails).
The NT domain can be specified on the commandline if the
auto-detection doesn't work for you (which is usually doesn't)

If you want to have the first proxy connect to another http proxy (like
one you can control, specify -r proxy2:port. The first proxy will then
connect to this remote proxy, which will be asked to connect to the 
requested destination. For more information regarding this feature, check
out http://dag.wieers.com/howto/ssh-http-tunneling/

If your proxy is more advanced, and does protocol inspection it will
detect that your connection is not a real HTTPS/SSL connection. You
can enable SSL encryption (using -e), which will work around this
problem, however, you need to setup stunnel4 on the other side, or
connect to a process that understands SSL itself.

When all this is in place, execute an "ssh foobar" and you're in business!

# Environment Variables

Proxytunnel can make use of the following environment variables:

```
PROXYUSER		Username for the proxy-authentication
PROXYPASS		Password for the proxy-authentication
REMPROXYUSER		Username for remote proxy-authentication
REMPROXYPASS		Password for remote proxy-authentication
HTTP_PROXY		Primary proxy host and port information
			Format: HTTP_PROXY=http://<host>:<port>/
```

# Authentication File

Proxytunnel can read authentication data from a file (-F/--passfile)

The format for this file is:
```
<field> = <value>
<field> = <value>
etc
```

One entry per line, 1 space before and after the equal sign.

The accepted fields are:
 * proxy_user
 * proxy_passwd
 * remproxy_user
 * remproxy_passwd

Share and Enjoy!

Jos Visser <josv@osp.nl>
Mark Janssen <maniac@maniac.nl>
