/* From Exercism, Isogram */
// Damn wtf it works anywhere but Exercism, fml

bool is_isogram(const char phrase[]){
    int len= strlen(phrase);

    for(int i=0; i<len; i++){
        if(heap[i] != ' ' && heap[i] != '-'){
            for(int j=i+1; j<len; j++){
                if(heap[i]==heap[j]){
                    return false;
                }
            }
        }
    }
    return true;
}
