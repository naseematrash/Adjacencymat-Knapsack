#include <stdlib.h>
#include <stdio.h>
#define MAX_WEIGHT 20
#define ITEMS 5
int bigger(int a, int b);
int knapSack(int weights[], int values[], int selected_bool[]);




int main() {
    char items[ITEMS] = {'A', 'B', 'C', 'D', 'E'};
    int array[ITEMS][2];
    char letter;

    //input the weight and value for each element
    for (int i = 0; i < ITEMS; i++) {
        scanf(" %c %d %d", &letter, &array[i][0], &array[i][1]);
    }


//making a list for values and weights
    int values[ITEMS];
    int weights[ITEMS];
    for (int i = 0; i < ITEMS; i++){
        values[i]=array[i][1];
        weights[i]=array[i][0];
    }


    int selected_bool[ITEMS] = {0};

    int biggestvalue = knapSack(weights, values, selected_bool);
    printf("Maximum profit: %d\n", biggestvalue);

    printf("Selected items: ");
    for (int i = 0; i < ITEMS; i++) {
        if (selected_bool[i]!=0){
            printf("%c ", items[i]);
        }
    }
    printf("\n");


    return 0;
}


/*
here im using the algorithm that ive learned in course
algorthims 1
solving the  knapsack problem using dynamic programming

*/
int knapSack(int weights[], int values[], int selected_bool[]) {

    int i, w;
    int table[ITEMS + 1][MAX_WEIGHT + 1];


//iterates over each item and knapsack weight,
//filling in the table the maximum value that can be achieved

    for (i = 0; i <= ITEMS; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (weights[i - 1] <= w)
                table[i][w] = bigger(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
            else
                table[i][w] = table[i - 1][w];
        }
    }

    /*
    after filling the table ,get maximum value item
    and fills the selected_bool
    */
    int selectedvalues = table[ITEMS][MAX_WEIGHT];
    w = MAX_WEIGHT;
    for (i = ITEMS; i > 0 && selectedvalues > 0; i--) {
        if (selectedvalues == table[i - 1][w])
            continue;
        else {
            selected_bool[i - 1] = 1;
            selectedvalues -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return table[ITEMS][MAX_WEIGHT];
}

int bigger(int a, int b) {
    if(a>b){
        return a;
    }
    else{
        return  b;
    }
}
