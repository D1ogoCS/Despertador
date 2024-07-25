#include <stdio.h>
#include <threads.h>
#include <time.h>
#include <unistd.h>

int minutos=100,hora=100,stopMostrarH=0,notificacaoSonora=1,atraso=0,dslMsg=0;

void menu(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    atraso=60-tm.tm_sec;
    printf("\n%02d:%02d\n", tm.tm_hour, tm.tm_min);
    printf("\n1-Definir Despertador\n2-Desligar Despertador\n3-Silenciar Alarme\n4-Ativar Alarme\n5-Ver Despertador\n6-Sair\nDigite o que deseja:\n");
}

void mostrarHoraAtual() {
    while(1){
        if(stopMostrarH==0){
            menu();
        }
        sleep(atraso);
    }
}

void alarme() {
    while(1){
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        if(tm.tm_hour!=hora&&tm.tm_min!=minutos){
            dslMsg=0;
        }
        if(tm.tm_hour==hora&&tm.tm_min==minutos&&dslMsg==0){
            sleep(1);
            if(notificacaoSonora==1){
            	printf("\a");
            }
            printf("\nHora de acordar!  Clique 9 para parar.");
            sleep(2);
        }
    }
}

int main() {
    thrd_t despertador,relogio;
    int opcao,a=1,inHora,inMinutos,status=1;
    
    if (thrd_create(&relogio, mostrarHoraAtual, NULL) != thrd_success) {
        printf("Erro ao criar thread.\n");
        return 1;
    }
            
    while(a==1){
        
        scanf("%d",&opcao);
        
        switch(opcao){
        case 1:
        
            stopMostrarH=1;
        
            do{
                printf("\nDigite as horas:");
                scanf("%d",&inHora);
            }
            while(inHora<0||inHora>23);
            
            do{
                printf("\nDigite os minutos:");
                scanf("%d",&inMinutos);
            }
            while(inMinutos<0||inMinutos>59);
            
            hora=inHora;
            minutos=inMinutos;
            
            status=thrd_create(&despertador, alarme, NULL);
             
            if(status==1){
                printf("Erro ao criar thread.\n");
            }
            
            notificacaoSonora=1;
            dslMsg=0;
            
            printf("Despertador para as %02d:%02d \n",hora,minutos);
            
            menu();
            
            stopMostrarH=0;
            
            break;
        case 2:
            if(status==0){
                pthread_cancel(despertador);
                printf("Despertador desligado!");
                status=1;
            }
            else{
                printf("Impossivel desligar porque não possuia alarmes!");    
            }
            menu();
            break;
        case 3:
            notificacaoSonora=0;
            printf("\nAlarme suspenso!\n");
            menu();
            break;
        case 4:
            notificacaoSonora=1;
            printf("\nAlarme ativo!\n");
            menu();
            break;
        case 5:
            if(status==1){
                printf("Não possui alarme!");
            }
            else{
                printf("\n O alarme está para as %02d:%02d",hora,minutos);
            }
            menu();
            break;
        case 6:
            a=2;
            pthread_cancel(relogio);
            if(status==0){
                pthread_cancel(despertador);
            }
            break;
        case 9:
            dslMsg=1;
            menu();
            break;
        default:
            break;
        }
        
    }
    
    printf("Saiu do Despertador!");
    
    return 0;

}
