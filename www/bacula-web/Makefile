# Created by: Dan Langille <dan@langille.org>
# $FreeBSD: head/www/bacula-web/Makefile 359653 2014-06-28 04:44:35Z miwi $

PORTNAME=	bacula-web
DISTVERSION=	6.0.0
CATEGORIES=	sysutils www
MASTER_SITES=	http://www.bacula-web.org/files/bacula-web.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dan@langille.org
COMMENT=	Bacula-web provides a summarized output of Bacula jobs

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PHP=	gd gettext session
WANT_PHP_WEB=	yes

OPTIONS_DEFINE=		MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	PGSQL

SUB_FILES=	pkg-message
BACULAWEB_HOME?=	${PREFIX}/www/bacula-web

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql=yes
USE_MYSQL=		yes
SUB_LIST+=		REQ_MYSQL=mysql
USE_PHP+=		pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=yes
SUB_LIST+=		REQ_PGSQL=postgresql
USE_PHP+=		pdo_sqlite
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-sqlite=yes
SUB_LIST+=		REQ_PGSQL=sqlite
USE_PHP+=		pdo_sqlite
.endif

do-install:
	@${ECHO} "Installing in ${BACULAWEB_HOME}"
	${MKDIR} ${STAGEDIR}${BACULAWEB_HOME}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${BACULAWEB_HOME}

post-install:
	${ECHO_CMD} '@owner www' > ${TMPPLIST}
	${ECHO_CMD} '@group www' >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${BACULAWEB_HOME} -not -type d | ${SORT} | \
	${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${BACULAWEB_HOME} -type d | ${SORT} -r | \
	${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	${ECHO_CMD} '@owner' >> ${TMPPLIST}
	${ECHO_CMD} '@group' >> ${TMPPLIST}

.include <bsd.port.mk>
