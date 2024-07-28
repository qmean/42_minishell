a | b | c => a o , b o , c o => main -> a -> b -> c -> main
a => fd 0 == stin fd 1 == stdout || main -> a -> main
a | b | c > a.txt  main -> a -> b -> c -> a.txt
a | b | c >> "dfjiwjof"
### a < a.txt | b | c > b.txt
= (a.txt -> a) -> b -> (c -> b.txt)


1 a.txt
2 a

a.txt -> redir:1
arg[0] = a.txt
arg[1] = a
arg[2] = NULL

a.txt > b > c.txt | d
a >> b 
file[1] a.txt
file[2] b.txt
data b

### ls -a | echo -n
1. ls -a input:stdin output: 2
2. echo -n input:2 output: 3
3. input:3 output:stdout

### cmd 5개 일때
main -> a -> b -> c -> d -> e -> main

- main 에서 할 일 = dup2(a.pipe[1], 1), close(a.pipe[0]), close(a.pipe[1])
- 