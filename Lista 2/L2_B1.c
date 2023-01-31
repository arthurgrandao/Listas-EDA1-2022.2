int faz_conta_direito(int parcelas, char op) {
    int x[parcelas];
    
    for (int i = 0; i < parcelas; i++)
    {
        scanf("%d", x+i);
        if (op == '+' && i > 0) 
            x[0] += x[i];
        else if (op == '-' && i > 0) 
            x[0] -= x[i];
    }
    
    return x[0]; 
}