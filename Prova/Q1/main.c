int multiplicaMatrizes(int *v1, int *v2, int *v3, int n){
	int i, j, k;

	if(v1 != NULL && v2 != NULL && v3 != NULL){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                v3[i*n + j] = 0;
                for(k=0;k<n;k++){
                    v3[i*n + j] += v1[i*n + k] * v2[k*n + j];
                }
            }
        }
		return TRUE;
	}
    return FALSE;
}