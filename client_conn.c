#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libpq-fe.h"

void do_exit(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}
///**
// * For PQsetSSLKeyPassHook_OpenSSL to provide password for SSL Key
// **/
//int ssl_password_provider(char *buf, int size, PGconn *conn)
//{    
//    const char * default_key_password = "secretclientpass";
//    strcpy(buf, default_key_password);
//    return strlen(default_key_password);
//}
/**
 * Sample program to make a connection and check server version
 */
int main() 
{
    printf("begin...");
    fflush(NULL);
//    PQsetSSLKeyPassHook_OpenSSL( ssl_password_provider );
//    PGconn *conn = PQconnectdb("host=172.17.0.3 port=5432 user=postgres dbname=postgres sslmode=require connect_timeout=4 password=mysecretpassword");
    PGconn *conn = PQconnectdb("user=doadmin password=l5al4hwte8qmj6x8 host=db-postgresql-sfo2-nextgen-do-user-1067699-0.db.ondigitalocean.com port=25060 dbname=treetracker_dev sslmode=require");
    if (PQstatus(conn) == CONNECTION_BAD) 
    {
        fprintf(stderr, "Connection to DB failed: %s\n", PQerrorMessage(conn));
        do_exit(conn);
    }
    printf("Server version: %d\n", PQserverVersion(conn));
    PQfinish(conn);
    return 0;
}
