int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int* results = (int*)malloc(queries_count * sizeof(int));
    if(results == NULL){
        *result_count = 0;
        return NULL;
    }
    for (int i=0;i<queries_count;i++){
        int count =0;
        for (int j=0;j<strings_count;j++){
            if (strcmp(queries[i],strings[j])==0){
                count++;
            }
        }
        results[i]=count;
    }
    *result_count = queries_count;
    return results;

}
