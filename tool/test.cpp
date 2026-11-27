while(n){
        d=n%10;
        n/=10;
        if(pre_cond==0){
            if(pre_d<d) pre_cond=2;
            else if(pre_d>d) pre_cond=1;
        }
        else{
            if(pre_d==d) continue;
            if(pre_d<d) cond=2;
            else if(pre_d>d) cond=1;
            else if(pre_d<d){ //tang
                if(pre_cond==2) continue;
                doc_cnt++;
            }
            else if(pre_d>d){ //giam
                if(pre_cond==1) continue;
                doc_cnt++;
            }
        }
        pre_cond=cond;
        pre_d=d;
        if(doc_cnt>2) return false;
    }