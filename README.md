# listen0: TCP listen() backlog parameter demo
Bart Massey 2024

I used this little pair of C programs to explore the effects
of setting the "backlog" parameter of the Linux `listen`
syscall to small values (0 or 1).

To use these, run `listener` with the desired backlog
parameter value as an argument. Then run instances of
`sender` as desired. Hitting return on a sender will cause
it to try to send its one-byte message and terminate.

I learned a lot from this exercise: mostly that small
backlog values don't necessarily do what you expect and
aren't particularly useful in practice.

Here's a few refs that explains some of what's going on:

* A general tutorial: <https://www.alibabacloud.com/blog/tcp-syn-queue-and-accept-queue-overflow-explained_599203>
  
* A detailed description: <https://veithen.io/2014/01/01/how-tcp-backlog-works-in-linux.html>

* A discussion of the pratical implications: <https://utcc.utoronto.ca/~cks/space/blog/unix/ListenBacklogMeaning>


# License

This work is licensed under the "MIT License". Please see the file
`LICENSE.txt` in this distribution for license terms.
