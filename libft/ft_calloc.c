#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	// on ecrit comme ca sinon nmemb * size risque d'overflow avant la comparaison a SIZE_MAX
	if (size != 0 && nmemb > SIZE_MAX / size)
        	return (NULL);
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
