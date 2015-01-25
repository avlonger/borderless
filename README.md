# Maximal Borderless Factors

## Compilation

```
$ make
```

## Average Values

To find average length of maximal borderless factor for all words
of length from 2 to 10 over the alphabet of size 5 use command

```
$ ./bin/average -b 2 -e 10 -a 5 BORDERLESS
```

You will see something like

```
n = 2	answer = 1.8000000000
n = 3	answer = 2.7600000000
n = 4	answer = 3.7200000000
n = 5	answer = 4.7120000000
n = 6	answer = 5.7027200000
n = 7	answer = 6.7006080000
n = 8	answer = 7.6984960000
n = 9	answer = 8.6980838400
n = 10	answer = 9.6976409600
```

## Time Measuring

To measure time required by the algorithms use command

```
$ ./bin/measure
```

## More info

For usage type

```
$ ./bin/average -h
$ ./bin/measure -h
```
