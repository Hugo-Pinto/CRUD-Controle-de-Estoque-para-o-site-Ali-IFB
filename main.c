/**********************************
Neste trabalho será feito um sistema de controle de estoque de um grande
site de vendas online, o site Ali-IFB (não tão grande assim…). Neste sistema será
possível cadastrar novos produtos, Consultar produtos, atualizar informações sobre
os produtos já existentes e remover (vender) estes produtos. Ou seja criaremos um
sistema CRUD (Create, Read, Update and Delete) para a entrada e saída de
produtos do site Ali-IFB.
Para construí-lo precisamos entender quais informações precisaremos
armazenar em um dado produto. Um produto é composto por:
● Nome do produto (Máximo de 50 caracteres);
● País de Origem (Máximo de 50 caracteres);
● Quantidade de itens;
● Código simplificado formado por 8 caracteres no padrão “PPIFBDDD”,
onde:
○ PP: dois primeiros caracteres do país de origem em Maiúsculo;
○ IFB: aparece em todos os produtos os três caracteres: “IFB”;
○ DDD: código de três dígitos variando de 000 a 999 de acordo
com a ordem de registro de produtos.
Exemplo de Código: “BRIFB003” significa que é um produto feito no
Brasil e foi o terceiro produto a ser cadastrado no sistema.
 
Cadastrar novo produto
Ao selecionar a opção de n° 1 o programa deve cadastrar um novo produto
recebendo do usuário as seguintes informações (Além das seguintes mensagens
para o usuário):
● Nome do produto:
● País de origem:
● Quantidade de itens:
Após isso deve ser gerado um novo código de acordo com a ordem de
registro do produto.
 
Atualizar informações de um produto
Ao selecionar a opção de n° 2 o programa deve receber como entrada o
código do produto. Caso não encontre o produto deve-se emitir a mensagem
“Código inválido!” e voltar ao menu principal.
1. Alterar nome: O produto recebe um novo nome para o produto;
2. Alterar país de origem: O produto recebe um novo país de origem;
3. Adicionar mais itens: O produto recebe uma quantidade de itens a ser
adicionado ao estoque atual.
Obs.: Deve-se atualizar o código do produto nos caracteres de país de
origem, caso seja alterado o país de origem do produto. Caso permaneça o mesmo
país de origem, não deve ser alterado o código.
 
Vender Produto
Ao selecionar a opção de n° 3 deve-se receber como entrada o código do
produto. Caso não encontre o produto deve-se emitir a mensagem “Código
inválido!” e voltar ao menu principal. Caso o encontre deve-se receber a
quantidade de itens a serem vendidas.
● A quantidade de itens a ser vendido deve ser maior ou igual a zero e
não deve ser maior que o estoque disponível. Caso seja negativo,
deve-se emitir a mensagem: “Valor inválido, digite novamente” e
receber uma nova quantidade. Caso seja maior, deve-se emitir a
mensagem “Não existem itens suficientes para este produto” e
receber uma nova quantidade.
Após a venda do produto deve-se voltar ao menu principal.
 
Consultar informações de um produto
Ao selecionar a opção de n° 4 deve-se receber como entrada o código do
produto. Caso não encontre o produto deve-se emitir a mensagem “Código
inválido!” e voltar ao menu principal. Caso o encontre deve-se exibir todas as
informações contidas deste produto.
 
Consultar quantidade de todos os produtos
Ao selecionar a opção de n° 5 deve-se exibir todos os produtos (Código de
Barras e quantidade de itens), um em cada linha.
*********************************/
 
 
#include "estruturas.h"
#include "converte.h"
 
 
 
int main()
{
    int ax = 20;
    int controlle =0;
    int estoque = 0;
    int verifica=0;
    int inteiros[qtd];
    int aux_vendas=0;
    int ordem_produto=0;
    int opcao1=0, opcao2=0;
    int qtdProdutos=0, qtdAdicional=0;
    char aux_pp[3], nomePais[50], Codigo_aux[8], aux_codigo[8];
    char DDD_AUX[size];
 
    for(int i=0; i<size; i++)
    {
        if(i==size-1){
 
        }
        else
        {
            DDD_AUX[i] = ' ';
        }
    }
 
    do
    {
        puts("+----------------------------------------------------------------------+");
        puts("|     CONTROLE DE ESTOQUE ALI-IFB                                      |");
        puts("|     1-cadastrar novo produto;                                        |");
        puts("|     2-atualizar informacoes de um produto;                           |");
        puts("|     3-vender produto                                                 |");
        puts("|     4-consultar informacoes de um produto;                           |");
        puts("|     5-consultar quantidade de todos produtos;                        |");
        puts("|     6-finalizar programa;                                            |");
        puts("+----------------------------------------------------------------------+");
        puts("\nseleciona a opcao desejada: \n");
        scanf("%d",&opcao1);
        switch(opcao1)
        {
        case 1:
            if(estoque<20)
            {
                getchar();
                printf("\nnome do produto: ");
                scanf("%[^\n]s",&produto[qtdProdutos].nome_produto);
                getchar();
 
                printf("\npais de origem: ");
                scanf("%[^\n]s",&nomePais);//variavel auxiliar pra receber o nome do pais e assim pegar seu codigo PP
                strcpy(produto[qtdProdutos].pais_origem, nomePais);
                getchar();
                printf("\nqtd de itens: ");
                scanf("%d",&produto[qtdProdutos].qtd_items);
 
                for(int i=0; i<2; i++)
                {
                    aux_pp[i] = toupper(aux_pp[i] = nomePais[i]);//pegando as duas primeiras iniciais do pais de origem e tornando em maiusculo
                }
                strcpy(produto[qtdProdutos].PP,aux_pp);
                strcpy(Codigo_aux, aux_pp);
                strcat(Codigo_aux, "IFB");
                strcpy(produto[qtdProdutos].codigo,Codigo_aux);
 
                cria_codigo(ordem_produto, DDD_AUX);
 
                strcat(produto[qtdProdutos].codigo,DDD_AUX);
                printf("\n");
                inteiros[qtdProdutos] = ordem_produto;
 
 
 
                qtdProdutos = qtdProdutos + 1;
                ordem_produto = ordem_produto + 1;
                estoque = estoque + 1;
            }
            else{
                printf("\nNao e possivel adicionar mais produtos no estoque\n");
            }
            break;
        case 2:
            controlle = 0;
            printf("\ndigite o codigo do produto: ");
            scanf("%s",&aux_codigo);
            for(int i=0; i<qtd; i++)
            {
                if (strcmp(aux_codigo,produto[i].codigo) == 0)
                {
                    printf("\n1-alterar nome;\n2-alterar pais de origem;\n3-adicionar mais itens;\n");
                    scanf("%d",&opcao2);
                    switch(opcao2)
                    {
                    case 1:
                        getchar();
                        printf("\ndigite o novo nome do produto: ");
                        scanf("%[^\n]s",&produto[i].nome_produto);
                        //getchar();
                        controlle = 0;
                        controlle = controlle + 1;
                        break;
                    case 2:
                        getchar();
                        printf("\ndigite o nome do pais de origem: ");
                        scanf("%[^\n]s",&nomePais);
                        getchar();
 
                        for(int i=0; i<2; i++)
                        {
                            aux_pp[i] = toupper(aux_pp[i] = nomePais[i]);//pegando as duas primeiras iniciais do pais de origem e tornando em maiusculo
                        }
                        /*
                        for(int i=0; i<qtd; i++)
                        {
                            if (strcmp(aux_codigo,produto[i].codigo) == 0)
                            {*/
                                //incrementar o i, e o qtd
                                strcpy(produto[i].PP,aux_pp);                       //como muda o nome do pais de origem, e necessario
                                strcpy(Codigo_aux, aux_pp);                         //gerar um novo codigo para o mesmo
                                strcat(Codigo_aux, "IFB");
                                strcpy(produto[i].codigo,Codigo_aux);
                                cria_codigo(inteiros[i], DDD_AUX);
                                strcat(produto[i].codigo,DDD_AUX);
                                strcpy(produto[i].pais_origem, nomePais);
                            //}
                        //}
                        controlle = 0;
                        controlle = controlle + 1;
                        break;
                    case 3:
                        printf("\ndigite a qntd de itens que deseja aumentar: ");
                        scanf("%d",&qtdAdicional);
                        produto[i].qtd_items = produto[i].qtd_items + qtdAdicional;// somando a quantidade anterior
                        controlle = 0;
                        controlle = controlle + 1;
                        break;
                    default:
                        printf("\nopcao invalida, voltando ao menu anterior\n");
                        break;
                    }
                }
            }
            if(controlle==0)
            {
                printf("\ncodigo invalido!\n");
            }
            break;
 
        case 3:
            controlle = 0;
            puts("\ndigite o codigo do produto: ");
            scanf("%s",&aux_codigo);
            for(int z=0; z<qtd; z++)
            {
                if (strcmp(aux_codigo,produto[z].codigo) == 0)
                {
 
                    do
                    {
                        printf("\ndigite a quantidade que deseja vender: ");
                        scanf("%d",&aux_vendas);
 
                        if(aux_vendas < 0)
                        {
                            printf("\nvalor invalido! ");
                        }
                        if(aux_vendas > produto[z].qtd_items)
                        {
                            printf("\nNao existem itens suficientes para este produto!");
                        }
                        if(aux_vendas>=0 && aux_vendas<=produto[z].qtd_items)
                        {
                            produto[z].qtd_items = produto[z].qtd_items - aux_vendas;
                            printf("\nqtd restante: %d\n",produto[z].qtd_items);
                            controlle = 0;
                            controlle = controlle + 1;
                            if(produto[z].qtd_items == 0)
                            {
                                for(int j=z; j<ax; j++)
                                {
                                    strcpy(produto[j].nome_produto, produto[j+1].nome_produto);
                                    strcpy(produto[j].pais_origem, produto[j+1].pais_origem);
                                    produto[j].qtd_items = produto[j+1].qtd_items;
                                    strcpy(produto[j].codigo, produto[j+1].codigo);
                                    inteiros[j]=inteiros[j+1];
                                }
                                qtdProdutos = qtdProdutos - 1;
                                controlle = 0;
                                controlle = controlle + 1;
                                estoque = estoque - 1;
                            }
                            verifica = 1;
                        }
                    }
                    while(verifica!=1);
                }
            }
            if(controlle==0)
            {
                printf("\ncodigo invalido!\n");
            }
            break;
 
        case 4:
            puts("\ndigite o codigo do produto: ");
            scanf("%s",&aux_codigo);
            controlle = 0;
 
            for(int i=0; i<qtd; i++)
            {
                if (strcmp(aux_codigo,produto[i].codigo) == 0)
                {
                    printf("\nnome do produto: %s",produto[i].nome_produto);
                    printf("\npais de origem: %s",produto[i].pais_origem);
                    printf("\nquantidade: %d",produto[i].qtd_items);
                    printf("\ncodigo do produto: %s",produto[i].codigo);
                    printf("\n");
 
                }
                else{
                    controlle = controlle + 1;
                }
            }
 
            if(controlle == 20){
                printf("\ncodigo invalido!\n");                 //a variavel controle é incrementada sempre que
            }                                                   //o codigo nao for encontrado no vetor, caso chegue a
                                                                //20, significa que nenhuma posição do vetor possui esse codigo
            break;
        case 5:
            for(int i=0; i<qtd; i++)
            {
                printf("\n%s        %d\n",produto[i].codigo, produto[i].qtd_items, inteiros[i]);
            }
            break;
        case 6:
            puts("\nvoce saiu;\n");
            opcao1 = 6;
            break;
        default:
            printf("\nopcao invalida\n");
        }
    }
    while(opcao1!=6);
}
