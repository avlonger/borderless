# Maximal Unbordered Factors

## Average Values

You can find the difference between the length of a string and the length of its maximal unbordered factor
for different alphabets and string lengths in text format
[here](https://github.com/avlonger/unbordered/blob/master/results/Average%20difference/Between%20n%20and%20maximal%20unbordered%20factor/Text/Alphabet_size_2_3_4_5.txt)
and in graph format
[here](https://github.com/avlonger/unbordered/blob/master/results/Average%20difference/Between%20n%20and%20maximal%20unbordered%20factor/Images/Alphabet_size_2_3_4_5.png).

You can find the difference between the length of a string and its minimal period
[here](https://github.com/avlonger/unbordered/blob/master/results/Average%20difference/Between%20n%20and%20minimal%20period/Text/Alphabet_size_2_3_4_5.txt)
and in graph format
[here](https://github.com/avlonger/unbordered/blob/master/results/Average%20difference/Between%20n%20and%20minimal%20period/Images/Alphabet_size_2_3_4_5.png).
 
## Comparison of the Algorithms

You can find comparison of the average running time of the algorithms in graph format 
[here](https://github.com/avlonger/unbordered/blob/master/results/All%20algorithms/Images/Alphabet_size_2.png)
and
[here](https://github.com/avlonger/unbordered/blob/master/results/Basic%20and%20modified%20border%20array%20algorithms/Images/Alphabet_size_2.png).

Running times of the algorithms in text format and more graphs can be found [here](https://github.com/avlonger/unbordered/tree/master/results/).
   
## Compilation

```
$ make
```
  
## Usage

To find the average length of the maximal unbordered factor for all words
of length from 2 to 10 over the alphabet of size 5 use command

```
$ ./bin/average -b 2 -e 10 -a 5 UNBORDERED
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
