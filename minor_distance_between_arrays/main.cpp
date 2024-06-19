#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;


void printing_array(int array_x[], int array_size){
    for(int i = 0; i < array_size; i++){
        cout << array_x[i] << " ";
    }
    cout << endl;
    }

void sorting_array(int array_x[], int array_size){
    int aux = 0;
    for(int i = 0; i < array_size; i++){
        for(int j = i; j < array_size; j++){
            if(array_x[i] > array_x[j]){
                aux = array_x[i];
                array_x[i] = array_x[j];
                array_x[j] = aux;
            }
        }
    }
}

int* merge_sort(int array_x[], int array_size){
    if (array_size <= 2){
        sorting_array(array_x, array_size);
        return array_x;
    }
    else{
        int aux_array_size = array_size/2;
        if (array_size % 2 != 0){
            aux_array_size += 1;
        }
        int first_half_array[aux_array_size];
        int second_half_array[array_size - aux_array_size];
        int *first_half_sorted_array;
        int *second_half_sorted_array;
        for(int i = 0; i < aux_array_size; i++){
            first_half_array[i] = array_x[i];
            if (!((array_size % 2 != 0) && (i == (aux_array_size - 1))))
                second_half_array[i] = array_x[i + aux_array_size];
        }
        first_half_sorted_array = merge_sort(first_half_array, aux_array_size);
        second_half_sorted_array = merge_sort(second_half_array, array_size - aux_array_size);
        for(int i = 0; i < aux_array_size; i++){
            array_x[i] = first_half_sorted_array[i];
            if (!((array_size % 2 != 0) && (i == (aux_array_size - 1))))
                array_x[i + aux_array_size] = second_half_sorted_array[i];
        }
        sorting_array(array_x, array_size);
        return array_x;
    }
}


int binary_search_array(int start, int end_array, int array_y[], int array_y_size, int reference_number, int* array_y_min_value, int smallest_distance){
    int middle = (start+end_array)/2;
    int current_value = abs(reference_number - array_y[middle]);
    int previous_value;
    int next_value;
    int final_value;
    if (middle == 0){
        previous_value = INT_MAX;
        next_value = abs(reference_number - array_y[middle+1]);
    }
    else if(middle == (array_y_size - 1)){
        previous_value = abs(reference_number - array_y[middle-1]);
        next_value = INT_MAX;
    }
    else{
        previous_value = abs(reference_number - array_y[middle-1]);
        next_value = abs(reference_number - array_y[middle+1]);
    }
    if (((current_value < previous_value) && (current_value < next_value)) || (start = end_array)){
        if (current_value < smallest_distance)
            *array_y_min_value = array_y[middle];
        return current_value;
    }
    else{
        if (previous_value < next_value){
            final_value = binary_search_array(start, middle, array_y, array_y_size, reference_number, array_y_min_value, smallest_distance);
        }
        else{
            final_value = binary_search_array(middle + 1, end_array, array_y, array_y_size, reference_number, array_y_min_value, smallest_distance);
        }
        return final_value;
    }

}


void finding_smallest_distance(int array_x[], int array_y[], int array_x_size, int array_y_size){
        int array_x_min_value = INT_MAX;
        int aux_min_value = INT_MAX;
        int array_y_min_value = INT_MAX;
        int *pointer_y_min_value = &array_y_min_value;
        int smallest_distance = INT_MAX;
        if (array_x[array_x_size-1] < array_y[0]){
            cout << "Min difference is between " << array_y[0] << " and " << array_x[array_x_size-1] << " which is " << array_y[0] - array_x[array_x_size-1];
        }
        else if (array_y[array_y_size-1] < array_x[0]){
            cout << "Min difference is between " << array_x[0] << " and " << array_y[array_y_size-1] << " which is " << array_x[0] - array_y[array_y_size-1];
        }
        else{
            for(int i = 0; i < array_x_size; i++){
                aux_min_value = binary_search_array(0, array_y_size - 1, array_y, array_y_size, array_x[i], pointer_y_min_value, smallest_distance);
                if(aux_min_value < smallest_distance){
                    array_x_min_value = array_x[i];
                    smallest_distance = aux_min_value;
                }
            }
           cout << "Min difference is between " << array_x_min_value << " and " << array_y_min_value << " which is " << smallest_distance;
        }
}

int main()
{

    int array_one_size;
    int array_two_size;
    cout << "Enter the size of array 1: " << endl;
    cin >> array_one_size;
    cout << "Enter the size of array 2: " << endl;
    cin >> array_two_size;
    int array_one[array_one_size];
    int array_two[array_two_size];
    cout << "Enter numbers of array 1: (one per line)" << endl;
    for(int i = 0; i < array_one_size; i++){
        cin >> array_one[i];
    }
    cout << "Enter numbers of array 2: (one per line)" << endl;
    for(int i = 0; i < array_two_size; i++){
        cin >> array_two[i];
    }
    merge_sort(array_one, array_one_size);
    merge_sort(array_two, array_two_size);
    finding_smallest_distance(array_one, array_two, array_one_size, array_two_size);
    return 0;
}
