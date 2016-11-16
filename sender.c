#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis.h>

int main(int argc, char **argv) 
{
    const char *host = "rrvarravlx";
    const char *queue = "DSM_QUEUE";
    int   port = 6379;
    struct timeval timeout = {2, 0}; // 2 secs
    redisContext *c;
    redisReply *reply;

    printf("Redis DSM Client QUEU: %s...\n", queue);
    c = redisConnect(host, port);
    if (c == NULL || c->err) {
        if (c) {
            printf("Error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Error: Failed to allocate redisContext");
        }
        exit(1);
    }

    /* ping check */
    reply = redisCommand(c, "PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /* reply = redisCommand(c, "RPUSH %s {\"host\":\"ME\",\"id\":1}", queue); */
    reply = redisCommand(c, "RPUSH %s %s", queue, "{\"id\":1,\"host\":\"hello\"}");
    printf("RPUSH Response: %s\n", reply->str);
    freeReplyObject(reply);



    redisFree(c);
    printf("Done...\n");
    exit(0);

}
