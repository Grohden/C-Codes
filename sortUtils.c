void swapVariables(int *i, int *j){
    *i = (*i) + (*j);
    
    *j = (*i) - (*j);
    *i = (*i) - (*j);
}
