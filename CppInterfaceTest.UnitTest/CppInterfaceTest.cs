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
            using (CppInterface<ICalculator> calculatorWrapper = CppInstanceFactory<ICalculator>.CreateInstance())
            {
                ICalculator calculator = calculatorWrapper.Object;
                Assert.IsNotNull(calculator);
                Assert.AreEqual(5, calculator.Add(1, 4));
            }
        }
    }
}
