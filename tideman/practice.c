
void print_winner(void)
{
    // TODO


               for(int j = 0; j < candidate_count; j++)
        {
            if(locked[0][j] == false)
            {
                int winner = j;
                for(int k = 1; k < candidate_count; k++)
                    {
                        if(locked[k][j] == true)
                        {
                            winner = -1;
                        }
                    }
                if(winner != -1)
                {
                    printf("%s\n", candidates[winner]);
                }
            }
        }
        return;
}


        for(int i = 0; i < candidate_count; i++)
        {
            bool isWinner=true;
            for(int j = 0; j < candidate_count; j++)
            {
                if(locked[j][i]){
                    isWinner=false;
                    break;
                }
            }
            if(isWinner){
                printf("%s\n", candidates[i]);
            }
        }
    return;
}