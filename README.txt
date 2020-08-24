Name & Class Account: Christina Tran, cssc2367
Class Information: CS570 Section #02, Summer 2020
Assignment Information: Assignment #0
Filename: README.txt

Files Manifest: count.h, alphabetcount.c, specialcharcount.c, makefile, 
                README.txt, testalphabetcount.c, testspecialcharcount.c 
Compile Instructions: 
    -To generate testalphabet executable file: make testalphabet
    -To generate testspecial executable file: make testspecial 
Operating Instructions:
    -./testalphabet 
    -./testspecial
Results:
    -Results will be written to a folder: result 
    -In result, there will be two txt files 
        1.result.txt    
            -This file will store the count frequency of alphabet count
            -My test results were:
            A -> 111804
            B -> 62436
            C -> 18612
            D -> 22308
            E -> 27324
            F -> 14124
            G -> 13596
            H -> 128436
            I -> 164340
            J -> 6600
            K -> 4752
            L -> 29040
            M -> 170808
            N -> 33000
            O -> 33924
            P -> 57948
            Q -> 792
            R -> 8712
            S -> 108240
            T -> 133716
            U -> 7128
            V -> 2904
            W -> 83952
            X -> 0
            Y -> 37356
            Z -> 0
            a -> 2861232
            b -> 494472
            c -> 747252
            d -> 1764444
            e -> 4855752
            f -> 751212
            g -> 795696
            h -> 2689632
            i -> 2421936
            j -> 28512
            k -> 396660
            l -> 1699236
            m -> 880044
            n -> 2476320
            o -> 2732268
            p -> 504900
            q -> 27984
            r -> 2168364
            s -> 2357256
            t -> 3157968
            u -> 1008480
            v -> 273900
            w -> 1001088
            x -> 46860
            y -> 693396
            z -> 12936 
        2.specialresult.txt 
            -This file will store the count frequency of special characters
            -My test results were:
            , -> 745668
            . -> 798072
            : -> 15708
            ; -> 32340
            ! -> 63228
List of Design Decisions:
    1. Access directories and files through use of the directory steam and path
    2. Search for only txt files
    3a. Algorithm for alphabetcount.c 
        -Count the frequency and store upper and lower case characters 
    3b. Algorithm for specialcharcount.case
        -Count the frequency and store the 5 special characters
    4. Print the results to a new folder
List of Extra Features: None
List of Known Deficiencies/Bugs: None
List of Lesson Learned: 
    1. Utilization of a path to access data
    2. How to access a directory stream
    2. Using fuctions from <dirent.h>
