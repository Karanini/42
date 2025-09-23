# JE N'AI TOUJOURS PAS VALIDE L'EXAM DONC JE NE PEUX PAS GARANTIR QUE CE CODE FONCTIONNE

## CORRECTIONS DES FONCTIONS AUXILIAIRES

### 1. ft_strchr - Corriger la boucle infinie
**Problème :** La condition de la boucle while ne vérifie pas si s[i] est NULL avant de le comparer
**Solution :** Ajouter une vérification null pour s[i]
```c
while (s[i] && s[i] != c)
    i++;
```

### 2. ft_memcpy - Implémentation
**Problème :** Implémentation incorrecte
**Solution :**
```c
void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return (dest);
}
```

### 3. ft_memmove - Corriger la condition de direction
**Problème :** La condition pour déterminer quand utiliser ft_memcpy vs copie arrière est inversée
**Solution :** Utiliser ft_memcpy quand dest < src, pas quand dest > src
```c
void *ft_memmove(void *dest, const void *src, size_t n)
{
    if (dest < src)  // Changé de dest > src
        return (ft_memcpy(dest, src, n));
    else if (dest == src)
        return (dest);
    size_t i = n;
    while (i > 0)
    {
        i--;
        ((char *)dest)[i] = ((char *)src)[i];
    }
    return (dest);
}
```

## CORRECTIONS DE STR_APPEND_MEM

### 4. Correction du calcul de taille
**Problème :** Calcul de taille incorrect quand *s1 est NULL
**Solution :**
```c
size_t size1 = *s1 ? ft_strlen(*s1) : 0;
```

### 5. Condition de copie mémoire
**Problème :** Vérification null manquante avant memcpy
**Solution :**
```c
if (*s1)
    ft_memcpy(tmp, *s1, size1);
```

## CORRECTIONS PRINCIPALES DE GET_NEXT_LINE

### 6. Ajouter la recherche de newline dans la boucle while
**Solution :** Ajouter à la fin de la boucle while(!tmp)
```c
b[0] = '\0';  // Vider le buffer après str_append_str
int read_ret = read(fd, b, BUFFER_SIZE);
if (read_ret == -1)
    return (NULL);
if (read_ret == 0)  // Gérer EOF
    break;
b[read_ret] = 0;
tmp = ft_strchr(b, '\n');  // Rechercher newline dans le nouveau contenu
```

### 7. Vider le buffer dans la boucle while
**Problème :** Le buffer n'est pas vidé après avoir ajouté son contenu à ret
**Solution :** Ajouter après str_append_str dans la boucle while
```c
if (!str_append_str(&ret, b))
    return (NULL);
b[0] = '\0';  // Vider le buffer
```

### 8. Gérer la valeur de retour read égale à 0
**Problème :** Break manquant sur EOF
**Solution :** Ajouter après la vérification read_ret == -1
```c
if (read_ret == 0)
    break;
```

### 9. Ajouter vérification null avant str_append_mem
**Solution :** Encapsuler le traitement de newline dans une condition
```c
if (tmp)
{
    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        free(ret);
        return (NULL);
    }
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
}
```

### 10. Déplacer le contenu restant du buffer
**Solution :** Ajouter après le bloc str_append_mem dans la condition if(tmp)
```c
ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
```

### 11. Gérer le cas où tmp est NULL
**Solution :** Ajouter un bloc else après if(tmp)
```c
else
{
    b[0] = '\0';
    if (!ret || !*ret)
    {
        free(ret);
        return (NULL);
    }
}
```

## ORDRE D'IMPLÉMENTATION
1. Corriger d'abord les fonctions auxiliaires (ft_strchr, ft_memcpy, ft_memmove)
2. Corriger la fonction str_append_mem
3. Appliquer les corrections get_next_line dans l'ordre (6-11)
4. Tester minutieusement avec diverses entrées

## BUGS CORRIGÉS
- **ft_strchr** : Ajout de la vérification s[i] != NULL pour éviter la boucle infinie
- **ft_memmove** : Correction de la condition dest < src au lieu de dest > src
- **get_next_line** : Vider le buffer, gérer EOF, traiter les newlines correctement
- **str_append_mem** : Vérification NULL pour *s1 avant calcul de taille
