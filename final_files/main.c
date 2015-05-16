

int main(){
  int M, N, status;
  char *nome_mapa, *log;
  char **mapa;
  barco b;
  
	scanf("%s", nome_mapa);
	log = "log.txt";
	mapa = leia_mapa(nome_mapa, &M, &N);
  status = 1;	
  b = posiciona_barco(mapa, M,  N);
  escreva_mapa_tela(mapa, M, N);
  escreva_mapa_arquivo(log, mapa, M, N);
	while(status){
	  status = rema_barco(mapa, M, N, b);
	  if(status == 2){
	      escreva_mapa_tela(mapa, M, N);
        escreva_mapa_arquivo(log, mapa, M, N);
	      printf("VOCÊ VENCEU!\n");
	      break;
	   }
	  if(status == 0){
	      escreva_mapa_tela(mapa, M, N);
        escreva_mapa_arquivo(log, mapa, M, N);
	      printf("GAME OVER!\n");
	      break;
	   }
	  dispara_tiros(mapa, M, N, log, &status);
	  if(status == 0){
	      escreva_mapa_tela(mapa, M, N);
        escreva_mapa_arquivo(log, mapa, M, N);	   
	      printf("GAME OVER!\n");
	      break;
	   }
	  escreva_mapa_tela(mapa, M, N);
    escreva_mapa_arquivo(log, mapa, M, N);
    
  }
	    
	free(nome_mapa);
	free(log);
	destroi_mapa(mapa, M);
}
