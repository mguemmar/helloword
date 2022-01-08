#include <stdio.h>
#include <curl/curl.h>
 
int main()
{
  CURLcode resultat;
  CURL *curl;
 
  curl = curl_easy_init();
  if(curl) {
    
    /* Configuer les options */
    curl_easy_setopt(curl, CURLOPT_URL, "file:///Users/mehdi-g/dev/langagec/helloword/dev.properties");
  
    /* Lancer la requête pour lire le fichier des propriétés, resultat contiendra le code résultat */
    resultat = curl_easy_perform(curl);

    /* Vérifier les erreurs  */
    if(resultat != CURLE_OK) {
      fprintf(stderr, "Echec dans la lecture du fichier de propriétés, veuillez vérfier : %s\n",
              curl_easy_strerror(resultat));
 
    } 
    /* fermer la connection */
    curl_easy_cleanup(curl);
  }
  return 0;
}