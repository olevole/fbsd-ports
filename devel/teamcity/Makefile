# New ports collection makefile for:    devel/teamcity
#
# $FreeBSD: head/www/teamcity/Makefile 300897 2012-07-14 14:29:18Z beat $
#

PORTNAME=	teamcity
PORTVERSION=	8.0
CATEGORIES=	devel java
MASTER_SITES=	http://download-ln.jetbrains.com/teamcity/
DISTNAME=       TeamCity-${PORTVERSION}

MAINTAINER=	olevole@olevole.ru
COMMENT=	Continuous Integration for Everybody

WRKSRC=		${WRKDIR}/TeamCity

USE_JAVA=	yes
NO_BUILD=	yes
USE_RC_SUBR=	teamcity

TEAMCITY_USER?=	${WWWOWN}
TEAMCITY_GRP?=	${WWWGRP}
TEAMCITY_HOME?=	${PREFIX}/TeamCity

SUB_LIST+=	TEAMCITY_USER=${TEAMCITY_USER} TEAMCITY_HOME=${TEAMCITY_HOME}

do-install:
		@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${TEAMCITY_HOME})
		${CHOWN} -R  ${TEAMCITY_USER}:${TEAMCITY_GRP} ${TEAMCITY_HOME}

		@for dir in `${FIND} ${TEAMCITY_HOME} -name bin -type d`; do \
			${CHOWN} -h -R ${BINOWN}:${BINGRP} $$dir; \
			${FIND} $$dir -type f -exec ${CHMOD} ${BINMODE} "{}" \; ; \
		done

		@${FIND} -s ${TEAMCITY_HOME} -not -type d | ${SORT} | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
		@${FIND} ${TEAMCITY_HOME} -type d | ${SORT} -r | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
