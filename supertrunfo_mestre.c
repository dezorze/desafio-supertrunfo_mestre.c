#include <stdio.h>

int main() {
    char estado1[50], codigo1[20], cidade1[50];
    char estado2[50], codigo2[20], cidade2[50];
    int pontosTuristicos1, pontosTuristicos2;
    float pib1, area1;
    float pib2, area2;
    unsigned long int populacao1, populacao2;
    float pibpercapita1, pibpercapita2;
    float densidade1, densidade2;
    float score1, score2;
    
    // Leitura da Carta 1
    printf("=== CARTA 1 - NÍVEL MESTRE ===\n");
    printf("Digite o Estado da carta 1:\n");
    scanf("%49s", estado1);

    printf("Digite o Código do Estado da carta 1:\n");
    scanf("%19s", codigo1);

    printf("Digite a Cidade da carta 1:\n");
    scanf("%49s", cidade1);

    printf("Digite a Populacao da Cidade da carta 1:\n");
    scanf("%lu", &populacao1);  // Correção: %lu para unsigned long int

    printf("Digite o Número de pontos turisticos da Cidade da carta 1:\n");
    scanf("%d", &pontosTuristicos1);

    printf("Digite o PIB da Cidade da carta 1:\n");
    scanf("%f", &pib1);

    printf("Digite a Área da Cidade da carta 1:\n");
    scanf("%f", &area1);

    // Leitura da Carta 2
    printf("\n=== CARTA 2 - NÍVEL MESTRE ===\n");
    printf("Digite o Estado da carta 2:\n");
    scanf("%49s", estado2);

    printf("Digite o Código da carta 2:\n");
    scanf("%19s", codigo2);

    printf("Digite a Cidade da carta 2:\n");
    scanf("%49s", cidade2);

    printf("Digite a Populacao da carta 2:\n");
    scanf("%lu", &populacao2);  // Correção: %lu para unsigned long int

    printf("Digite o Número de pontos turisticos da carta 2:\n");
    scanf("%d", &pontosTuristicos2);

    printf("Digite o PIB da carta 2:\n");
    scanf("%f", &pib2);

    printf("Digite a Área da carta 2:\n");
    scanf("%f", &area2);

    // CÁLCULOS DEPOIS de ler todos os valores
    pibpercapita1 = (populacao1 > 0) ? (pib1 / populacao1) : 0;
    pibpercapita2 = (populacao2 > 0) ? (pib2 / populacao2) : 0;
    
    densidade1 = (area1 > 0) ? (populacao1 / area1) : 0;
    densidade2 = (area2 > 0) ? (populacao2 / area2) : 0;

    // Cálculo do score (poder da carta). O certo era por peso para ponderar melhor.
    // score1 = (populacao1 * 0.1) + (pontosTuristicos1 * 50) + (pib1 * 0.0001) + (area1 * 0.01);
    // score2 = (populacao2 * 0.1) + (pontosTuristicos2 * 50) + (pib2 * 0.0001) + (area2 * 0.01);
    
    score1 = (populacao1 + pontosTuristicos1 + pib1 + area1);
    score2 = (populacao2 + pontosTuristicos2 + pib2 + area2);

    // Exibição das duas cartas
    printf("\n--- Dados da carta 1 - NÍVEL MESTRE ---\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %lu habitantes\n", populacao1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("PIB: R$ %.2f\n", pib1);
    printf("Área: %.2f Km2\n", area1);
    printf("PIB per capita: R$ %.2f\n", pibpercapita1);
    printf("Densidade Populacional: %.2f hab/Km2\n", densidade1);
    printf("Poder da carta 1: %.2f\n", score1);
    
    printf("\n--- Dados da carta 2 - NÍVEL MESTRE ---\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %lu habitantes\n", populacao2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("PIB: R$ %.2f\n", pib2);
    printf("Área: %.2f Km2\n", area2);
    printf("PIB per capita: R$ %.2f\n", pibpercapita2);
    printf("Densidade Populacional: %.2f hab/Km2\n", densidade2);
    printf("Poder da carta 2: %.2f\n", score2);

    // Determinar vencedor
    printf("\n=== RESULTADO FINAL ===\n");
    if (score1 > score2) {
        printf("A CARTA 1 (%s) VENCEU com %.2f pontos!\n", cidade1, score1);
    } else if (score2 > score1) {
        printf("A CARTA 2 (%s) VENCEU com %.2f pontos!\n", cidade2, score2);
    } else {
        printf("EMPATE! Ambas as cartas têm %.2f pontos!\n", score1);
    }

    return 0;
}
