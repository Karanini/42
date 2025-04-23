#include <stdio.h> // pour printf
#include <stdlib.h> // pour free
#include "libft.h" // ou déclare ft_strdup ici si tu n'as pas encore de libft.h

int main(void)
{
    const char *original = "Hello, World!";
    char *copy;

    copy = ft_strdup(original);

    if (copy == NULL)
    {
        printf("Erreur d'allocation mémoire.\n");
        return (1);
    }

    printf("Original : %s\n", original);
    printf("Copie     : %s\n", copy);

    free(copy); // important pour éviter une fuite mémoire
    return (0);
}
