using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CppInterfaceTest.UnitTest
{
    [TestClass]
    public class CppInterfaceTest
    {
        [DeploymentItem("CppInterface.dll")]
        [TestMethod]
        public void AddTest()
        {
            ICalculator calculator = CppInstanceFactory.CreateCalculator();
            Assert.IsNotNull(calculator);
            Assert.AreEqual(5, calculator.Add(1, 4));
        }
    }
}
