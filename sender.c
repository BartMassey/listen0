#include <assert.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    assert(s >= 0);
    struct sockaddr_in in = {
        .sin_family = AF_INET,
        .sin_port = htons(15501),
        .sin_addr = {htonl(INADDR_LOOPBACK)},
    };
    int r = connect(s, (struct sockaddr *) &in, sizeof in);
    assert(r >= 0);
    fprintf(stderr, "sender connected\n");
    getchar();
    char buf[1] = {'!'};
    r = write(s, &buf, 1);
    assert(r >= 0);
    r = close(s);
    assert(r >= 0);
    return 0;
}
