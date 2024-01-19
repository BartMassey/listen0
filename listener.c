#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int nq = 0;
    if (argc >= 2)
        nq = atoi(argv[1]);
    int s = socket(AF_INET, SOCK_STREAM, 0);
    assert(s >= 0);
    /* https://stackoverflow.com/a/24194999 */
    int enable = 1;
    int r = setsockopt(s, SOL_SOCKET, SO_REUSEADDR,
                         (void *) &enable, (socklen_t) sizeof(enable));
    assert(r >= 0);
    struct sockaddr_in in = {
        .sin_family = AF_INET,
        .sin_port = htons(15501),
        .sin_addr = {htonl(INADDR_LOOPBACK)},
    };
    r = bind(s, (struct sockaddr *) &in, sizeof in);
    if (r < 0) {
        perror("bind");
        exit(1);
    }
    r = listen(s, nq);
    assert(r >= 0);
    int c = accept(s, (struct sockaddr *) 0, (socklen_t *) 0);
    assert(c >= 0);
    fprintf(stderr, "listener connected\n");
    char buf[1];
    r = read(c, buf, 1);
    assert(r == 1);
    assert(buf[0] == '!');
    r = read(c, buf, 1);
    assert(r == 0);
    r = close(s);
    assert(r >= 0);
    return 0;
}
