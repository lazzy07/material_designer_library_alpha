#pragma once
#include "Core.hpp"
#include "KernelLibrary.hpp"
#include "../types/matd/Argument.hpp"
#include "../engine/matd/Queue.hpp"
#include "../graphs/core/MaterialProject.hpp"

namespace MATD{
  namespace CORE{
    /**
     * @brief Material Designer class, which is used to create and manage Material Designer projects
     * 
     */
    class MaterialDesigner{
      public:
    	MaterialDesigner();
        ~MaterialDesigner();
      
      /**
       * @brief Selects the device to use for computation
       * 
       * @param platformId Platform ID to select
       * @param deviceId Device ID to select
       * @return std::vector<size_t> List of selected devices
       */
    	std::vector<size_t> SelectDevice(uint8_t platformId, uint8_t deviceId);
    	
      /**
       * @brief Set the Kernel Library Folder object
       * 
       * @param path Path to the kernel library folder
       */
      void SetKernelLibraryFolder(const std::string& path) const;

      /**
       * @brief Create an integer object
       * 
       * @param val Value of the integer
       * @return MATD::Int* Integer object
       */
      static MATD::Int* CreateInt(int val);

      /**
       * @brief Create a float object
       * 
       * @param val Value of the float
       * @return MATD::Float* Float object
       */
    	static MATD::Float* CreateFloat(float val);

      /**
       * @brief Create a buffer object
       * 
       * @param val Value of the buffer
       * @param size Size of the buffer, in # of elements
       * @param elem_size Size of each element in the buffer
       * @param argType Type of the buffer
       * @return MATD::Buffer* Buffer object
       */
    	static MATD::Buffer* CreateBuffer(void* val, size_t size, size_t elem_size, buf_type argType=MATD::ARG_TYPE::DEVICE_READ);

      /**
       * @brief Create a grayscale texture object
       * 
       * @param bitType Bit depth of the texture
       * @param width Width of the texture
       * @param height Height of the texture
       * @param argType Type of the texture
       * @return MATD::GrayscaleTexture* Grayscale texture object
       */
    	static MATD::GrayscaleTexture* CreateGrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType = MATD::ARG_TYPE::DEVICE_READ);
    	
      /**
       * @brief Create a color texture object
       * 
       * @param bitType Bit depth of the texture
       * @param width Width of the texture
       * @param height Height of the texture
       * @param argType Type of the texture
       * @return MATD::ColorTexture* Color texture object
       */
      static MATD::ColorTexture* CreateColorTexture(MATD_TEXTURE_BIT_TYPE bitType, size_t width, size_t height, buf_type argType = MATD::ARG_TYPE::DEVICE_READ);
    	
      /**
       * @brief Create a work item object
       * 
       * @param kernel Kernel to create the work item for
       * @return MATD::WorkItem* Work item object
       */
      static MATD::WorkItem* CreateWorkItem(MATD::Kernel* kernel);

      /**
       * @brief Create a queue object
       * 
       * @return MATD::Queue* Queue object
       */
    	static MATD::Queue* CreateQueue();
      /**
       * @brief Create a number2 object
       * 
       * @param val Value of the number2
       * @return MATD::MatNumber2* Number2 object
       */
      static MATD::MatNumber2* CreateNumber2(MATD::Number2 val);
      
      /**
       * @brief Create a colorvec3 object
       * 
       * @param val Value of the colorvec3
       * @return MATD::MatColorVec3* Colorvec3 object
       */
      static MATD::MatColorVec3* CreateColorVec3(MATD::ColorVec3 val);

      /**
       * @brief Open a Material Editor project
       * 
       * @param JSONString JSON string of the project
       */
    	void OpenProject(const std::string& JSONString);

      /**
       * @brief Update a Material Editor project
       * 
       * @param JSONString JSON string of the project
       */
    	void UpdateProject(const std::string& JSONString) const;

      /**
       * @brief Set the selected graph, graph could be kernel graph, data graph or shader graph.
       * 
       * @param graphID ID of the graph to select
       */
    	void SetSelectedGraph(const std::string& graphID) const;

    /**
     * @brief Create a node in the selected graph
     * 
     * @param selectedGraphType Type of the selected graph, kernel, data or shader
     * @param JSONString JSON string of the node
     */
		void CreateNode(const std::string& selectedGraphType, const std::string& JSONString) const;

    /**
     * @brief Remove a node from the selected graph
     * 
     * @param selectedGraphType Type of the selected graph, kernel, data or shader
     * @param JSONString JSON string of the node
     */
		void RemoveNode(const std::string& selectedGraphType, const std::string& JSONString) const;
		
    /**
     * @brief Add a connection to the selected graph
     * 
     * @param selectedGraphType Type of the selected graph, kernel, data or shader
     * @param JSONString JSON string of the connection
     */
    void AddConnection(const std::string& selectedGraphType, const std::string& JSONString) const;

    /**
     * @brief Remove a connection from the selected graph
     * 
     * @param selectedGraphType Type of the selected graph, kernel, data or shader
     * @param JSONString JSON string of the connection
     */
		void RemoveConnection(const std::string& selectedGraphType, const std::string& JSONString) const;
		
    /**
     * @brief Update the selected graph
     * 
     * @param selectedGraphType Type of the selected graph, kernel, data or shader
     * @param JSONString JSON string of the graph
     */
    void Update(const std::string& selectedGraphType, const std::string& JSONString) const;

    /**
     * @brief Compile the kernel
     * 
     * @return std::string Compiled kernel
     */
    [[nodiscard]] std::string CompileKernel() const;

    /**
     * @brief Set this to be true if the Material Designer is used by the Material Designer App
     * 
     * @param isUsedByApp True if used by the app
     */
    static void SetUsedByMaterialDesignerApp(bool isUsedByApp) { m_IsUsedByMaterialDesignerApp = isUsedByApp; };

    /**
     * @brief Get if the Material Designer is used by the Material Designer App
     * 
     * @return bool True if used by the app
     */
    static bool GetUsedByMaterialDesignerApp() { return m_IsUsedByMaterialDesignerApp; };

    /**
     * @brief Get the Material project
     * 
     * @return Ref<MATD::GRAPH::MaterialProject> Material project that is currently open
     */
    [[nodiscard]] Ref<MATD::GRAPH::MaterialProject> GetNodeProject() const;

    /**
     * @brief Update the shader node data callback
     * 
     * @param nodeId Node ID that is updated
     * @param texture Texture data that is updated
     */
    static void UpdateShaderNodeData(int nodeId, MATD::DTYPES::Texture* texture);

    /**
     * @brief Set the shader node change callback
     * 
     * @param func Callback function
     */
    static void SetCallShaderNodeChangeCallback(void(*func)(int, MATD::DTYPES::Texture*)) { m_CallShaderNodeChangeCallback = func; }

    /**
     * @brief Call the shader node change callback
     * 
     * @param nodeId Node ID that is updated
     * @param texture Texture data that is updated
     */
    static void CallShaderNodeChangeCallback(int nodeId, MATD::DTYPES::Texture* texture) { m_CallShaderNodeChangeCallback(nodeId, texture); }

    private:
        Ref<MATD::CORE::KernelLibrary> m_KernelLibrary;
        Ref<MATD::GRAPH::MaterialProject> m_CurrentProject;
        inline static bool m_IsUsedByMaterialDesignerApp = false;
        inline static void(*m_CallShaderNodeChangeCallback)(int, MATD::DTYPES::Texture*);
    };
  };
}
