/*  This file is part of the Tufão project
    Copyright (C) 2011 Vinícius dos Santos Oliveira <vini.ipsmaker@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any
    later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TUFAO_HTTPSSERVER_H
#define TUFAO_HTTPSSERVER_H

#include "httpserver.h"

class QSslCertificate;
class QSslKey;

namespace Tufao {

namespace Priv {

struct HttpsServer;

} // namespace Priv

class HttpsServer : public HttpServer
{
    Q_OBJECT
public:
    explicit HttpsServer(QObject *parent = 0);

    /*!
      Destroys the object.
      */
    ~HttpsServer();

    void setLocalCertificate(const QSslCertificate &certificate);
    void setPrivateKey(const QSslKey &key);

protected:
    void incomingConnection(int socketDescriptor);

private:
    Priv::HttpsServer *priv;
};

} // namespace Tufao

#endif // TUFAO_HTTPSSERVER_H