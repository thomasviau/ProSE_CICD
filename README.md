[![Build Status](https://travis-ci.com/Nathan-LG/ProSE_CICD.svg?branch=master)](https://travis-ci.com/Nathan-LG/ProSE_CICD)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=alert_status)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD)

[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=coverage)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD) 
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=bugs)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=code_smells)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD)
[![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=ncloc)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD)

[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=sqale_rating)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=Nathan-LG_ProSE_CICD&metric=security_rating)](https://sonarcloud.io/dashboard?id=Nathan-LG_ProSE_CICD)

# CI sur ProSE

Suivre ce dépot va vous permettre de mettre en place un processus d'intégration continue (CI) sur votre projet ProSE.

Les outils suivants seront mis en place :
* [SonarCloud](https://sonarcloud.io/) (aka [SonarLint](https://www.sonarlint.org/))
* [CppCheck](http://cppcheck.sourceforge.net/)

## Avertissement

Pensez à vérifier avec votre client si vous avez l'autorisation d'utiliser tous ces outils. Beaucoup d'entre eux nécessiteront de déployer le code sur des dépots **publics** en version gratuite !

## Comptes requis

* Un compte [GitHub](https://github.com)
    * Demander le  [GitHub Student Pack](https://education.github.com/pack/offers). Il permet de créer des dépots privés gratuitement et de faire des build privés sur [Travis CI](https://travis-ci.com).
* Un compte [SonarCloud](https://sonarcloud.io/)
    * Avec la version gratuite, vous pouvez l'utiliser uniquement sur des dépots publics. Autrement, vous pouvez installer [SonarQube](https://www.sonarqube.org/) sur un serveur (intégration avec Travis CI non testée).
* Un compte [Redmine ProSE](http://prose.eseo.fr/redmine)
* Un compte [Travis CI](https://travis-ci.com)

## Installation

### Compte GitHub

1. Créez un dépot public (sinon SonarCloud ne pourra pas fonctionner). Pour cela, la meilleure idée est de forker celui-ci. En effet, CMake est configuré avec la bonne arborescence.
2. Pensez à lier votre IDE à Git (menu Git ou VCS). Ca sera beaucoup plus simple pour vous.

### Compte SonarCloud

1. Connectez-vous avec votre compte GitHub.
2. Créez un nouveau projet SonarCloud
3. Lorsqu'on vous le demande, prenez l'option vous menant sur GitHub puis sélectionnez le dépot précédemment créé.
4. Lorsqu'on vous le demande, prenez l'offre gratuite (aka Open source).
5. Finissez par cocher votre dépot GitHub sur SonarCloud puis cliquez sur Set Up.

### Compte Travis CI

1. Connectez-vous avec votre compte GitHub. De cette façon, vos dépots seront automatiquement accessibles.
2. Liez votre compte Travis CI à votre compte GitHub (https://github.com/marketplace/travis-ci). Sélectionnez bien la version gratuite. Contactez Travis CI si vous avez des problèmes pour activer votre offre GitHub Student. Le support est très réactif.

**Vos comptes sont à présent configurés.**

### Dépot GitHub

1. Depuis le marketplace, activez l'intégration avec Travis CI, prenez l'option gratuite.

### Lien Travis - SonarCloud

1. Générez un token sur SonarCloud : My account ; Security. Entrez un nom de token, puis copiez le token généré.
2. Sur Travis CI, allez dans les options de votre projet. Créez une variable d'envrionnement intitulée `SONAR_TOKEN` ayant comme valeur le token précédement copié.
3. Sur SonarCloud, notez l'ID (key) de votre organisation. 
4. Dans le fichier `.travis.yml` sur votre dépot GitHub, changez la clé `organization` à la ligne 14 par l'ID de votre organisation.
5. Dans le fichier `sonar-project.properties`, changez les valeurs `sonar.projectKey`, `sonar.projectName` et `sonar.projectVersion` pour correspondre à votre projet. L'ID (key) de votre projet est trouvable directement sur SonarCloud. Les deux autres peuvent prendre le nom que vous voulez.

### CMake

1. Dans le fichier `CMakeLists.txt` sur votre dépot GitHub, changez le nom de votre projet (constante `PROSE_PROJECT_NAME`) à la ligne 5.

## Utilisation

C'est tout simple ! Il vous suffit de push sur votre dépot Git. Travis va se déclencher tout seul et envoyer les résultats de SonarLint à SonarCloud. Ta Da !

Les tests CMocka et CppCheck sont accessibles depuis la console Travis CI.

## Fonctionnement

CMake permet de générer des Makefile (parce que entre nous, c'est chiant au possible !). Les cibles suivantes seront alors accessibles :

| Nom   | KeskeC |
|----------|:-------------|
| `PROSE_PROJECT_NAME` | Programme classique (src) |
| `PROSE_PROJECT_NAME + Test` | Tests unitaires (test) |
| coverage | Génération des fichiers de coverage |

La librairie CMocka est dans /test/cmocka. Le fichier header est `cmocka.h`, le .so est `CICD.so`.