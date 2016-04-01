# pg_udp

Simple contrib module to perform UDP queries

## pg_udp Functions

At this point there is just one function to send UDP query:

```
udp_send(host CSTRING, port INT, data CSTRING)
```
Connects to specified `host` and `port` and sends string `data`.

## Installation

To install `pg_udp` run in terminal:

```
make USE_PGXS=1
make install USE_PGXS=1
```

> Note: you may need to have `postgresql-server-dev` package installed on your system
