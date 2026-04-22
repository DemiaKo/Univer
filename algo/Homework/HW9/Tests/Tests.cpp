#include "pch.h"
#include "CppUnitTest.h"
#include "../HW9/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DijkstraTests
{
    TEST_CLASS(DijkstraTests)
    {
    public:
        TEST_METHOD(TestShortestPath_Basic)
        {
            Graph g(4);
            g.addEdge(0, 1, 1);
            g.addEdge(1, 2, 2);
            g.addEdge(0, 2, 4);
            g.addEdge(2, 3, 1);

            int* dist = g.dijkstra(0);

            Assert::AreEqual(0, dist[0]);
            Assert::AreEqual(1, dist[1]);
            Assert::AreEqual(3, dist[2]);
            Assert::AreEqual(4, dist[3]);

            delete[] dist;
        }

        TEST_METHOD(TestDisconnectedGraph)
        {
            Graph g(3);
            g.addEdge(0, 1, 5);

            int* dist = g.dijkstra(0);

            Assert::AreEqual(0, dist[0]);
            Assert::AreEqual(5, dist[1]);
            Assert::AreEqual(INT_MAX, dist[2]);

            delete[] dist;
        }

        TEST_METHOD(TestException_InvalidVertex)
        {
            Graph g(2);

            auto funcAdd = [&] { g.addEdge(0, 5, 10); };
            Assert::ExpectException<std::out_of_range>(funcAdd);

            auto funcRun = [&] { g.dijkstra(99); };
            Assert::ExpectException<std::out_of_range>(funcRun);
        }

        TEST_METHOD(TestException_NegativeWeight)
        {
            Graph g(3);
            auto func = [&] { g.addEdge(0, 1, -5); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestZeroWeightPath)
        {
            Graph g(3);
            g.addEdge(0, 1, 0);
            g.addEdge(1, 2, 5);

            int* dist = g.dijkstra(0);

            Assert::AreEqual(0, dist[0]);
            Assert::AreEqual(0, dist[1]);
            Assert::AreEqual(5, dist[2]);

            delete[] dist;
        }
    };
}