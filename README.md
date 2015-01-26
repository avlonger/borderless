# Maximal Borderless Factors

## Average Values

You can find the average length of the maximal borderless factor for different
alphabets and string lengths in text format
[here](https://github.com/avlonger/borderless/blob/master/results/average_max_borderless.txt).

The difference between the length of the string
and its maximal borderless factor in graph format can be found
[here](https://github.com/avlonger/borderless/blob/master/results/n_minus_max_borderless_2_3_4_5.png)
and
[here](https://github.com/avlonger/borderless/blob/master/results/n_minus_max_borderless_2.png).

The average values of minimal period for different alphabet sizes and string lengths
can be found [here](https://github.com/avlonger/borderless/blob/master/results/average_min_border.txt).

The average difference beetwen the length of the string and its minimal period in graph format
can be found
[here](https://github.com/avlonger/borderless/blob/master/results/n_minus_min_period_2_3_4_5.png)
and
[here](https://github.com/avlonger/borderless/blob/master/results/n_minus_min_period_2.png).
 
   
## Compilation

```
$ make
```
  
## Usage

To find the average length of the maximal borderless factor for all words
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

To find the average length of the maximal border for all words
of length from 2 to 10 over the alphabet of size 5 use command

```
$ ./bin/average -b 2 -e 10 -a 5 BORDER
```

You will see something like

```
n = 2	answer = 0.2000000000
n = 3	answer = 0.2400000000
n = 4	answer = 0.2800000000
n = 5	answer = 0.2880000000
n = 6	answer = 0.2972800000
n = 7	answer = 0.2993920000
n = 8	answer = 0.3010944000
n = 9	answer = 0.3014860800
n = 10	answer = 0.3018327040
```


## Compare algorithms

To compare time required by the algorithms use command

```
$ ./bin/compare_algorithms
```

You will see

```
BASIC_ALGORITHM: n = 100 t = 0.00000355
NAIVE_ALGORITHM: n = 100 t = 0.00005327
...
```

## More info

To see help message use commands

```
$ ./bin/average -h
$ ./bin/compare_algorithms -h
```
